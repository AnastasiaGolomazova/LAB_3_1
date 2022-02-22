#include "tablemodel.h"

TableModel::TableModel(QObject *parent): QAbstractTableModel(parent), data_(std::make_unique<QList<UnitInformation>>()){}

int TableModel::rowCount(const QModelIndex &parent) const
{
    return data_->size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    return Percentage + 1;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || data_->size() <= index.row())
    {
        return QVariant();
    }

    switch (role)
    {
    case Qt::TextAlignmentRole:
        if (index.column() == Name)
        {
             return Qt::AlignLeft;
        }
        else
        {
             return Qt::AlignRight;
        }
    case Qt::DisplayRole:
    case Qt::EditRole:
        {
            const UnitInformation &item = data_->at(index.row());

            switch (index.column())
            {
            case Name:
                return item.GetName();
            case Size:
                return item.GetSizeKb();
            case Percentage:
                return item.CalculatePercentage();
            }
        }
    }

    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
    {
        return QVariant();
    }

    switch (section)
    {
    case Name:
        return "Name";
    case Size:
        return "Size";
    case Percentage:
        return "Percentage";
    }

    return QVariant();
}

void TableModel::set_data(std::unique_ptr<QList<UnitInformation>> &&data)
{
    if (!data)
    {
        throw std::runtime_error("TableModel::set_data: The data is nullptr.");
    }

    beginResetModel();

    data_ = std::move(data);

    endResetModel();
}
