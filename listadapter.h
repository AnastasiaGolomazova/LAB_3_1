#ifndef LISTADAPTER_H
#define LISTADAPTER_H

#include <QLayout>
#include <QHeaderView>
#include <QTreeView>

#include "directoryobserver.h"
#include "unitInformation.h"
#include "tablemodel.h"

class ListAdapter : public directoryObserver
{
public:
    explicit ListAdapter(QLayout *layout);
    ~ListAdapter();

    void Update(std::unique_ptr<QList<UnitInformation>> &items) const;

private:
    TableModel *model_;

    QTreeView *view_;
};

#endif // LISTADAPTER_H
