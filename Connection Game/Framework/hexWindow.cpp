#include "hexWindow.h"
#include "ui_hexWindow.h"

HexWindow::HexWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HexWindow)
{
    ui->setupUi(this);
}

HexWindow::~HexWindow()
{
    delete ui;
}

void HexWindow::on_chooseButton_pressed()
{
    this->close();
}

void HexWindow::on_rematchButton_pressed()
{
    this->close();
    this->showMaximized();
}

void HexWindow::on_startButton_clicked(){

    QString nameP1, nameP2;
    nameP1=ui->txtP1->text();
    nameP2=ui->txtP2->text();

    bool finish=false;
    HexGame hex;
    HexBoard board;
    Player p1("jay", Piece::Color::BLUE, Player::NrPlayer::FIRST);
    Player p2("lia", Piece::Color::RED, Player::NrPlayer::SECOND);

    while(!finish)
    {
        //player1's turn
        ui->whoseTurn->setText(nameP1);
        //place pice
        if (hex.CheckBridge(board, p1) == "Blue won" || hex.CheckBridge(board, p1) == "Red Won")
        {
           //player1 won
           finish=true;
        }

        //player2's turn
        ui->whoseTurn->setText(nameP2);
        //place pice
        if (hex.CheckBridge(board, p2) == "Blue won" || hex.CheckBridge(board, p2) == "Red Won")
        {
            //player2 won
            finish=true;
        }
     }
}
