#include "yframe.h"

YFrame::YFrame(QWidget *parent) : QFrame(parent)
{

}

void YFrame::mousePressEvent(QMouseEvent *event)
{
    uint8_t maxCells=yBoard.GetBoard().size();
    const auto middleHeight=(this->height()-60-(maxCells-1)*40-6*maxCells)/2;
    size_t line = (event->y()-(middleHeight+20))/43;
    const auto middleWidth=(this->width()-yBoard.GetBoard().at(line).size()*40)/2;
    size_t column = (event->x()-middleWidth)/40;

    Player p1("jay", Piece::Color::BLUE, Player::NrPlayer::FIRST);
    if(line>=0 && line<yBoard.GetBoard().size() && column>=0 && column<yBoard.GetBoard().at(line).size())
    {
        p1.PlacePiece({line,column},yBoard);
    }
    update();
}

void YFrame::paintEvent(QPaintEvent *event)
{
    uint8_t maxCells=yBoard.GetBoard().size();
    const auto middleWidth=this->width()/2;
    const auto middleHeight=(this->height()-60-(maxCells-1)*40-6*maxCells)/2;
    uint8_t hexagonsVertices=6;

    Q_UNUSED(event);

    QPainter painter{this};
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(3);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    QPointF points[6] = {
                QPointF(middleWidth, middleHeight),
                QPointF(middleWidth+20, middleHeight+20),
                QPointF(middleWidth+20, middleHeight+40),
                QPointF(middleWidth, middleHeight+60),
                QPointF(middleWidth-20, middleHeight+40),
                QPointF(middleWidth-20, middleHeight+20)
            };
    QPointF pointscpy[6] = {
        QPointF(middleWidth, middleHeight),
        QPointF(middleWidth+20, middleHeight+20),
        QPointF(middleWidth+20, middleHeight+40),
        QPointF(middleWidth, middleHeight+60),
        QPointF(middleWidth-20, middleHeight+40),
        QPointF(middleWidth-20, middleHeight+20)
    };

    auto position=std::make_pair(0u, 0u);
    auto& [line, column]=position;
    for(;line<maxCells;++line)
    {
        for(column=0u;column<line+1;++column)
        {
            std::optional<Piece> p=yBoard.GetBoard().at(line).at(column);
            brush.setColor(p->colorToQColor(p->GetColor()));
            painter.setBrush(brush);
            painter.drawPolygon(points, hexagonsVertices);

            for(int index=0; index<hexagonsVertices; ++index){
                points[index].rx()+=40;
            }
        }
        for(int index=0; index<hexagonsVertices; ++index){
            pointscpy[index].rx()-=20;
            points[index].rx()=pointscpy[index].rx();
        }
        for(int index=0; index<hexagonsVertices; ++index){
            points[index].ry()+=45;
        }
    }

}

void YFrame::on_rematchButton_pressed()
{
    yBoard.ClearBoard();
    update();
}

