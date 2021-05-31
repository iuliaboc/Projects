#include "havannahWindow.h"
#include "ui_havannahWindow.h"

HavannahWindow::HavannahWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HavannahWindow)
{
    ui->setupUi(this);
}

HavannahWindow::~HavannahWindow()
{
    delete ui;
}

void HavannahWindow::on_chooseButton_pressed()
{
    this->close();
}

void HavannahWindow::on_rematchButton_pressed()
{
    this->close();
    this->showMaximized();
}

void HavannahWindow::on_startButton_clicked()
{
    QString nameP1, nameP2;
    nameP1=ui->txtP1->text();
    nameP2=ui->txtP2->text();

    bool finish=false;
    HavannahGame havannah;
    HavannahBoard board;
    Player p1("jay", Piece::Color::BLUE, Player::NrPlayer::FIRST);
    Player p2("lia", Piece::Color::RED, Player::NrPlayer::SECOND);

    while(!finish)
    {
        //player1's turn
        ui->whoseTurn->setText(nameP1);
        //place pice
        if (havannah.BFS_Bridge(board, p1.GetColor()) == true || havannah.CheckFork(board,p1.GetColor()) /*|| havannah.CheckRing(position, board)==true*/)
        {
           //player1 won
           finish=true;
        }

        //player2's turn
        ui->whoseTurn->setText(nameP2);
        //place pice
        if (havannah.BFS_Bridge(board, p2.GetColor()) == true || havannah.CheckFork(board,p2.GetColor()) /*|| havannah.CheckRing(position, board)==true*/)
        {
            //player2 won
            finish=true;
        }
     }
}
