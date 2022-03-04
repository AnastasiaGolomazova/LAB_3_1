#include "listadapter.h"

ListAdapter::ListAdapter(QLayout *layout)
{
    model_ = new TableModel();

    view_= new QTreeView();
    view_->setModel(model_);
    view_->setRootIsDecorated(false);
    view_->header()->setStretchLastSection(false);
    view_->header()->setMinimumSectionSize(75);
    view_->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    view_->header()->setSectionResizeMode(TableModel::Name, QHeaderView::Stretch);

    layout->addWidget(view_);
}

ListAdapter::~ListAdapter()
{
    delete model_;
    delete view_;
}

void ListAdapter::Update(std::unique_ptr<QList<UnitInformation>> &items) const
{
    model_->set_data(items);
}
