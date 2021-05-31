#ifndef HAVANNAHWINDOW_H
#define HAVANNAHWINDOW_H

#include <QWidget>
#include <QLabel>
#include"havannahgame.h"
#include"player.h"


namespace Ui {
class HavannahWindow;
}

class HavannahWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HavannahWindow(QWidget *parent = nullptr);
    ~HavannahWindow();

private slots:
    void on_chooseButton_pressed();
    void on_rematchButton_pressed();
    void on_startButton_clicked();

private:
    Ui::HavannahWindow *ui;
};

#endif // HAVANNAHWINDOW_H
