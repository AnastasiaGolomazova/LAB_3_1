#ifndef CHARTS_H
#define CHARTS_H

#include <QPieSeries>
#include <QBarSet>
#include <QBarSeries>
#include <QGraphicsLayout>
#include <QChart>

#include "unitInformation.h"

class Chart
{
public:
    virtual ~Chart() = default;

    QChart *CreateChart(const std::unique_ptr<QList<UnitInformation>> &items) const;

    virtual void DrawChart(QChart *chart, const std::unique_ptr<QList<UnitInformation>> &items) const = 0;
    void DrawLegend(QLegend *legend) const;
};

class PieChart : public Chart
{
public:
    void DrawChart(QChart *chart, const std::unique_ptr<QList<UnitInformation>> &items) const;
};

class BarChart : public Chart
{
public:
    void DrawChart(QChart *chart, const std::unique_ptr<QList<UnitInformation>> &items) const;
};

#endif // CHARTS_H
