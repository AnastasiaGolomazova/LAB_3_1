#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tablemodel.h"
#include "unitInformation.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow),group_by_folder_(new GroupByFolder()), group_by_type_(new GroupByType()), strategy_(nullptr), directory_view_(nullptr)
{
    ui->setupUi(this);

    fsModel = new QFileSystemModel(this);
    directory_model_ = new TableModel();
    fsModel->setRootPath("C:/SPPO/LAB_3_1/TEST");
    fsModel->setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks | QDir::AllDirs);
    fsModel->setRootPath(QString());

    ui->treeView->setModel(fsModel);
    ui->treeView->setHeaderHidden(true);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);

    list_adapter_ = new ListAdapter(ui->stackedWidget->layout());
    pie_chart_adapter_ = new PieChartAdapter(ui->stackedWidget->layout());
    bar_chart_adapter_ = new BarChartAdapter(ui->stackedWidget->layout());


    on_comboBox_currentIndexChanged(0);
    on_comboBox_2_activated(0);

    connect(ui->comboBox_2, &QComboBox::activated, this, &MainWindow::on_comboBox_2_activated);
    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &MainWindow::on_comboBox_currentIndexChanged);
    connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &MainWindow::on_treeView_clicked);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::select_folder(QString path){
    QModelIndex index = fsModel->index(path);

        while (index.isValid())
        {
            ui->treeView->expand(index);


            index = index.parent();
        }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
        if (index == 0) {
            strategy_ = group_by_folder_;
        }
       else if(index == 1){
            strategy_ = group_by_type_;
        }
        if (directory_view_ != nullptr)
        {
            strategy_->Attach(directory_view_);

            patternUpdate();
        }
}

void MainWindow::patternUpdate()
{
    QModelIndex index = ui->treeView->currentIndex();

    if (index.isValid())
    {
        const QString path = fsModel->filePath(index);

        strategy_->Explore(path);

    }
}

void MainWindow::on_treeView_clicked(const QItemSelection &selected, const QItemSelection &deselected)
{
    if (!selected.isEmpty()) {
        patternUpdate();
    }

}

void MainWindow::on_comboBox_2_activated(int index)
{
    if (index == 0) {
        directory_view_ = pie_chart_adapter_;
    }
   else if(index == 1){
        directory_view_ = bar_chart_adapter_;
    }
    else if(index == 2){
         directory_view_ = list_adapter_;
     }
    strategy_->Attach(directory_view_);
    patternUpdate();
    ui->stackedWidget->setCurrentIndex(index);
}

