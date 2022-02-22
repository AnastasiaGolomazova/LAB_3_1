#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tablemodel.h"
#include "unitInformation.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fsModel = new QFileSystemModel(this);
    directory_model_ = new TableModel();
    //fsModel->setRootPath(QDir::currentPath());
    fsModel->setRootPath("C:/SPPO/LAB_3_1/TEST");
    fsModel->setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks | QDir::AllDirs);
    fsModel->setRootPath(QString());

    ui->treeView->setModel(fsModel);
    ui->treeView->setHeaderHidden(true);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);

    ui->tableView->setModel(directory_model_);
    //ui->tableView->setRootIsDecorated(false);
    //ui->tableView->header()->setStretchLastSection(false);
    //ui->tableView->header()->setMinimumSectionSize(75);
    //ui->tableView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    QModelIndex index = fsModel->index("../TEST/");

        while (index.isValid())
        {
            ui->treeView->expand(index);

            index = index.parent();
        }

    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &MainWindow::on_comboBox_currentIndexChanged);
    connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &MainWindow::on_treeView_clicked);
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
    QModelIndex index = ui->treeView->currentIndex();

    if (index.isValid())
    {

            const QString path = fsModel->filePath(index);

            directory_model_->set_data((pattern->GetDirectoryInfo(path)));


    }

}



void MainWindow::on_treeView_clicked(const QItemSelection &selected, const QItemSelection &deselected)
{
    if (!selected.isEmpty()) {
        patternUpdate();
    }

}

