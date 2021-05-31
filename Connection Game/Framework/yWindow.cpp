#include "yWindow.h"
#include "ui_yWindow.h"

YWindow::YWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::YWindow)
{
    ui->setupUi(this);
}

YWindow::~YWindow()
{
    delete ui;
}

void YWindow::on_chooseButton_pressed()
{
    this->close();
}

void YWindow::on_rematchButton_pressed()
{
    this->close();
    this->showMaximized();
}

void YWindow::on_start_clicked()
{
    nameP1=ui->txtP1->text();
    nameP2=ui->txtP2->text();

    YGame y;
    y.Run();
}


