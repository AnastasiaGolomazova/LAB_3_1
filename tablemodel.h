#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>

#include "unitInformation.h"
#include "tablemodel.h"

class TableModel : public QAbstractTableModel
{
public:
    enum Column
    {
        Name,
        Size,
        Percentage
    };

    explicit TableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    void set_data(std::unique_ptr<QList<UnitInformation>> &data);

private:
    std::unique_ptr<QList<UnitInformation>> data_;
};

#endif // TABLEMODEL_H
