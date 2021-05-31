#ifndef HAVANNAHFRAME_H
#define HAVANNAHFRAME_H

#include <QWidget>
#include<QFrame>
#include<QPaintEvent>
#include<QPainter>
#include<QPen>
#include<QBrush>
#include<QMouseEvent>

#include"havannahBoard.h"
#include"player.h";

class HavannahFrame : public QFrame
{
    Q_OBJECT
public:
    explicit HavannahFrame(QWidget *parent = nullptr);
    void ClearBoardHavannah();

private slots:
    void on_rematchButton_pressed();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    HavannahBoard havannahboard;
};

#endif // HAVANNAHFRAME_H
