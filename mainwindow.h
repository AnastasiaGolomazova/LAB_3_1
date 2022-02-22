#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QItemSelection>

#include "groupingpattern.h"
#include "groupingbytype.h"
#include "groupingbyfolder.h"
#include "tablemodel.h"


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

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_treeView_clicked(const QItemSelection &selected, const QItemSelection &deselected);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *fsModel;
    std::shared_ptr<GroupingPattern> pattern;
    TableModel *directory_model_;


};

#endif // MAINWINDOW_H
