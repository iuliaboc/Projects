#ifndef HEXBOARD_H
#define HEXBOARD_H
#include"board.h"
#include"piece.h"
#include"player.h"
#include<set>
#include<queue>
#include<iostream>

class HexBoard :  public Board
{
public:
    std::vector<Board::Position> blueEntryPoints;
    std::vector<Board::Position> blueExitPoints;
    std::vector<Board::Position> redEntryPoints;
    std::vector<Board::Position> redExitPoints;

public:
    HexBoard();
   // std::optional<std::string> CheckBridge(const HexBoard& board, const Player& player);
};


#endif // HEXBOARD_H
