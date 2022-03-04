#ifndef CHARTADAPTERS_H
#define CHARTADAPTERS_H

#include <QLayout>
#include <QVBoxLayout>
#include <QChartView>


#include "directoryobserver.h"
#include "charts.h"

class ChartAdapter : public directoryObserver
{
public:
    ChartAdapter(std::unique_ptr<Chart> &&chart, QLayout *layout);
    ~ChartAdapter();

    void Update(std::unique_ptr<QList<UnitInformation>> &items) const;

private:
    std::unique_ptr<Chart> chart_;

    QChartView *view_;
};

class PieChartAdapter : public ChartAdapter
{
public:
    explicit PieChartAdapter(QLayout *layout);
};

class BarChartAdapter : public ChartAdapter
{
public:
    explicit BarChartAdapter(QLayout *layout);
};

#endif // CHARTADAPTERS_H
