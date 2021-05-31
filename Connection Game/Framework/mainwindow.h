#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <havannahWindow.h>
#include <hexWindow.h>
#include <yWindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_havannahButton_pressed();
    void on_hexButton_pressed();
    void on_yButton_pressed();

public:
    std::string game;

public slots:
    void on_exitButton_pressed();

private:
    Ui::MainWindow *ui;
    HavannahWindow m_havannah;
    HexWindow m_hex;
    YWindow m_y;
};
#endif // MAINWINDOW_H
