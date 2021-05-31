#ifndef HEXGAME_H
#define HEXGAME_H

#include"hexBoard.h"

class HexGame:public HexBoard
{
public:
    HexGame();

    std::optional<std::string> CheckBridge(const HexBoard& board, const Player& player);

     bool CheckIfWon(const HexBoard& board, const Player& player);
};

#endif // HEXGAME_H
