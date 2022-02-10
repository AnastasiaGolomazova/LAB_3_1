#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>

#include "groupingpattern.h"
#include "groupingbytype.h"
#include "groupingbyfolder.h"


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

private:
    Ui::MainWindow *ui;
    QFileSystemModel *fsModel;
    std::unique_ptr<GroupingPattern> pattern;


};

#endif // MAINWINDOW_H
