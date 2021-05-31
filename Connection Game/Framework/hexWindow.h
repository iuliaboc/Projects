#ifndef HEXWINDOW_H
#define HEXWINDOW_H

#include <QWidget>
#include <QLabel>
#include"hexgame.h"
#include"player.h"

namespace Ui {
class HexWindow;
}

class HexWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HexWindow(QWidget *parent = nullptr);
    ~HexWindow();

private slots:
    void on_chooseButton_pressed();
    void on_rematchButton_pressed();
    void on_startButton_clicked();

private:
    Ui::HexWindow *ui;
};

#endif // HEXWINDOW_H
