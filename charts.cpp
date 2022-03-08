#include "charts.h"
#include <QDebug>

QChart *Chart::CreateChart(const std::unique_ptr<QList<UnitInformation>> &items) const
{
    QChart *chart = new QChart();
    chart->setBackgroundRoundness(0);
    chart->layout()->setContentsMargins(0, 0, 0, 0);
    chart->setMargins({ 20, 20, 0, 20 });

    std::sort(items->begin(), items->end(), std::greater<UnitInformation>());
    auto item = items->cbegin();

    qint64 total_size = item ? item->GetFullSizeKb() : 0;

    if (total_size == 0)
    {
        chart->setTitle("The folder is empty.");

        return chart;
    }

    if (items->size() > 8)
    {
        std::advance(item, 7);

        qint64 size = 0;

        while (item != items->cend())
        {
            size += item->GetSizeKb();

            item = items->erase(item);
        }

        items->push_back(UnitInformation("Others", size, total_size));
    }

    DrawLegend(chart->legend());
    DrawChart(chart, items);
    //qDebug() << "Chart Create!";

    return chart;
}

void Chart::DrawLegend(QLegend *legend) const
{
    legend->setAlignment(Qt::AlignRight);
}

void PieChart::DrawChart(QChart *chart, const std::unique_ptr<QList<UnitInformation>> &items) const
{
    QPieSeries *series = new QPieSeries();
    series->setPieSize(1);

    for (const auto &item : *items)
    {
        qreal ratio = item.GetSizeKb() / item.GetFullSizeKb();
        series->append(item.GetName() + " (" + item.CalculatePercentage().toHtmlEscaped() + ")", ratio);
    }

    chart->addSeries(series);
}

void BarChart::DrawChart(QChart *chart, const std::unique_ptr<QList<UnitInformation>> &items) const
{
    QBarSeries *series = new QBarSeries();
    series->setBarWidth(1);

    for (const auto &item : *items)
    {
        QBarSet *set = new QBarSet(item.GetName() + " (" + item.CalculatePercentage().toHtmlEscaped() + ")");
        qreal ratio = item.GetSizeKb() / item.GetFullSizeKb();
        set->append(ratio);

        series->append(set);
    }

    chart->addSeries(series);
}
