#ifndef HEXFRAME_H
#define HEXFRAME_H

#include <QWidget>
#include<QFrame>
#include"piece.h"
#include"hexBoard.h"
#include<QPaintEvent>
#include<QMouseEvent>
class hexFrame : public QFrame
{
    Q_OBJECT
public:
    explicit hexFrame(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
private slots:
    void on_rematchButton_pressed();
private:
    HexBoard hexBoard;
};

#endif // HEXFRAME_H
