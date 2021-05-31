#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_havannahButton_pressed()
{
    m_havannah.showMaximized();
}

void MainWindow::on_hexButton_pressed()
{
    m_hex.showMaximized();
}

void MainWindow::on_yButton_pressed()
{
    m_y.showMaximized();
}

void MainWindow::on_exitButton_pressed()
{
    this->close();
}
