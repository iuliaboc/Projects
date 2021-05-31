#include "havannahframe.h"

HavannahFrame::HavannahFrame(QWidget *parent) : QFrame(parent)
{

}

void HavannahFrame::mousePressEvent(QMouseEvent *event)
{
    uint8_t maxCells = havannahboard.GetBoard().at(0).size();
    const auto startTop=(this->height()-60-(maxCells*2-1)*40-6*maxCells)/2;
    size_t line = (event->y()-(startTop+20))/45;
    const auto startLeft=(this->width()-havannahboard.GetBoard().at(line).size()*43)/2;
    size_t column = (event->x()-startLeft)/40;

    Player p1("jay", Piece::Color::BLUE, Player::NrPlayer::FIRST);
    if(line>=0 && line<havannahboard.GetBoard().size() && column>=0 && column<havannahboard.GetBoard().at(line).size())
    {
        p1.PlacePiece({line,column},havannahboard);
    }
    update();
}

void HavannahFrame::paintEvent(QPaintEvent *event)
{
    uint8_t maxCells = havannahboard.GetBoard().at(0).size();
    const auto middleWidth=(this->width()-maxCells*40)/2;
    const auto middleHeight=(this->height()-60-(maxCells*2-1)*40-6*maxCells)/2;
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
    for(;line<havannahboard.GetBoard().size();++line)
    {
        if(line==maxCells)
        {
            for(int index=0; index<hexagonsVertices; ++index){
                pointscpy[index].rx()+=40;
                points[index].rx()=pointscpy[index].rx();
            }
        }
        for(column=0u;column<havannahboard.GetBoard().at(line).size();++column)
        {
            std::optional<Piece> p=havannahboard.GetBoard().at(line).at(column);
            brush.setColor(p->colorToQColor(p->GetColor()));
            painter.setBrush(brush);
            painter.drawPolygon(points, hexagonsVertices);

            for(int index=0; index<hexagonsVertices; ++index){
                points[index].rx()+=40;
            }
         }
         for(int index=0; index<hexagonsVertices; ++index){
             if(line<maxCells)
             {
                pointscpy[index].rx()-=20;
             }
             else
             {
                pointscpy[index].rx()+=20;
             }
             points[index].rx()=pointscpy[index].rx();
         }
         for(int index=0; index<hexagonsVertices; ++index){
             points[index].ry()+=45;
         }
    }
}

void HavannahFrame::ClearBoardHavannah()
{
    havannahboard.ClearBoard();
    update();
}

void HavannahFrame::on_rematchButton_pressed()
{
    havannahboard.ClearBoard();
    update();
}
