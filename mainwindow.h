#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QItemSelection>
#include <QSplitter>
#include <QStackedWidget>

#include "groupbystrategy.h"
#include "listadapter.h"
#include "chartadapters.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void patternUpdate();
    void select_folder(QString path);

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_treeView_clicked(const QItemSelection &selected, const QItemSelection &deselected);
    
    void on_comboBox_2_activated(int index);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *fsModel;
    TableModel *directory_model_;
//
    directoryObserver *list_adapter_;
    directoryObserver *pie_chart_adapter_;
    directoryObserver *bar_chart_adapter_;
    QSplitter *splitter_;
    QVBoxLayout *vertical_layout_;

    GroupByStrategy *group_by_folder_;
    GroupByStrategy *group_by_type_;

    GroupByStrategy *strategy_;
    directoryObserver *directory_view_;

    void directory_Update();

    void combo_box_group_by_OnChanged(const int index);
    void combo_box_display_in_OnChanged(const int index);
    void tree_view_OnChanged(const QModelIndex &current, const QModelIndex &previous);

};

#endif // MAINWINDOW_H
