#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>

//#include "tableitem.h"
#include "unitInformation.h"


class TableModel : public QAbstractTableModel
{
public:
    TableModel();

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

    void set_data(std::unique_ptr<QList<UnitInformation>> &&data);

private:
    std::unique_ptr<QList<UnitInformation>> data_;
};

#endif // TABLEMODEL_H