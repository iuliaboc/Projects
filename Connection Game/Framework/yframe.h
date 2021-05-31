#ifndef YFRAME_H
#define YFRAME_H

#include <QWidget>
#include<QFrame>
#include<QPaintEvent>
#include<QPainter>
#include<QPen>
#include<QBrush>
#include<QMouseEvent>


#include"YBoard.h"
#include"player.h"

class YFrame : public QFrame
{
    Q_OBJECT
public:
    explicit YFrame(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
private slots:
    void on_rematchButton_pressed();
protected:
    YBoard yBoard;
};

#endif // YFRAME_H
