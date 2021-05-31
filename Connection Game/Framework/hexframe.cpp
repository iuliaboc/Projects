#include "hexframe.h"
#include<QPainter>
#include"piece.h"
#include<QPen>
#include<QBrush>
#include<QPointF>
hexFrame::hexFrame(QWidget *parent) : QFrame(parent)
{

}

void hexFrame::mousePressEvent(QMouseEvent *event)
{
    const auto startTop=(this->height()-60-(hexBoard.GetSize()-1)*40-6*hexBoard.GetSize())/2;
    size_t line = (event->y()-(startTop+20))/43;
    const auto startLeft=(this->width()-43*hexBoard.GetSize()*3/2)/2+20*line;
    size_t column = (event->x()-startLeft)/40;


    Player p1("jay", Piece::Color::BLUE, Player::NrPlayer::FIRST);
    if(line>=0 && line<hexBoard.GetBoard().size() && column>=0 && column<hexBoard.GetBoard().size())
    {
        p1.PlacePiece({line,column},hexBoard);
    }
    update();
}

void hexFrame::paintEvent(QPaintEvent *event)
{
  const auto middleWidth=(this->width()-43*(hexBoard.GetSize()*3/2))/2;
  const auto middleHeight=(this->height()-60-(hexBoard.GetSize()-1)*40-6*hexBoard.GetSize())/2;
  int hexagonsVertices=6;

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
  const size_t last=hexBoard.GetSize()-1;
  for(; line<hexBoard.GetSize(); ++line)
  {
      for(column=0u; column<hexBoard.GetSize(); ++column)
      {
          std::optional<Piece> p=hexBoard.GetBoard().at(line).at(column);
          brush.setColor(p->colorToQColor(p->GetColor()));
          painter.setBrush(brush);
          painter.drawPolygon(points, hexagonsVertices);

          pen.setColor(Qt::blue);
          painter.setPen(pen);
          if(line==0)
          {
              painter.drawLine(points[0],points[1]);
              painter.drawLine(points[0],points[5]);
          } else if(line==last) {
              painter.drawLine(points[3],points[2]);
              painter.drawLine(points[3],points[4]);
          }
          pen.setColor(Qt::red);
          painter.setPen(pen);
          if(column==0)
          {
              painter.drawLine(points[5],points[4]);
              painter.drawLine(points[4],points[3]);
          } else if(column==last) {
              painter.drawLine(points[0],points[1]);
              painter.drawLine(points[1],points[2]);
          }
          pen.setColor(Qt::black);
          painter.setPen(pen);

          for(int index=0; index<hexagonsVertices; ++index){
              points[index].rx()+=40;
          }

      }
      for(int index=0; index<hexagonsVertices; ++index){
          pointscpy[index].rx()+=20;
          points[index].rx()=pointscpy[index].rx();
      }
      for(int index=0; index<hexagonsVertices; ++index){
          points[index].ry()+=45;
      }
  }
}

void hexFrame::on_rematchButton_pressed()
{
    hexBoard.ClearBoard();
    update();
}
