#ifndef YWINDOW_H
#define YWINDOW_H

#include <QWidget>
#include <QLabel>
#include"ygame.h"
#include"player.h"

namespace Ui {
class YWindow;
}

class YWindow : public QWidget
{
    Q_OBJECT

public:
    explicit YWindow(QWidget *parent = nullptr);
    ~YWindow();

private slots:
    void on_chooseButton_pressed();
    void on_rematchButton_pressed();
    void on_start_clicked();

private:
    Ui::YWindow *ui;

public:
    QString nameP1, nameP2;
};

#endif // YWINDOW_H
