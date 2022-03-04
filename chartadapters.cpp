#include "chartadapters.h"

ChartAdapter::ChartAdapter(std::unique_ptr<Chart> &&chart, QLayout *layout)
    : chart_(std::move(chart))
{
    view_ = new QChartView(chart_->CreateChart(std::make_unique<QList<UnitInformation>>()));
    view_->setFrameShape(QFrame::StyledPanel);
    view_->resize(256, 0);
    view_->setSceneRect(0, 0, 256, 0);

    layout->addWidget(view_);
}

ChartAdapter::~ChartAdapter()
{
    delete view_;
}

void ChartAdapter::Update(std::unique_ptr<QList<UnitInformation>> &items) const
{
    QChart *previous = view_->chart();

    view_->setChart(chart_->CreateChart(items));

    delete previous;
}

PieChartAdapter::PieChartAdapter(QLayout *layout): ChartAdapter(std::make_unique<PieChart>(), layout){}

BarChartAdapter::BarChartAdapter(QLayout *layout): ChartAdapter(std::make_unique<BarChart>(), layout){
}
