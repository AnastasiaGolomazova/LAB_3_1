#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fsModel = new QFileSystemModel(this);
    //fsModel->setRootPath(QDir::currentPath());
    fsModel->setRootPath("C:/SPPO/LAB_3_1/TEST");
    ui->treeView->setModel(fsModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_comboBox_currentIndexChanged(int index)
{

        if (index == 0) {
            pattern = std::make_unique<GroupingByFolder>();
        }else{
            pattern = std::make_unique<GroupingByType>();
        }

    patternUpdate();

}

void MainWindow::patternUpdate()
{

}


