#ifndef PLAYER_H
#define PLAYER_H


#include"board.h"
#include"piece.h"
#include<fstream>
#include <iostream>
#include <exception>

class Player
{
public:
    enum class NrPlayer :uint8_t
    {
        FIRST,
        SECOND
    };
public:
    Player(const std::string& name, Piece::Color color, NrPlayer number);
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
    Board::Position PlacePiece(Board::Position position, Board& board);

    Piece::Color GetColor() const noexcept;
    Player::NrPlayer GetNrPlayer() const noexcept;

private:
    std::string m_name;
    Piece::Color m_color;
    NrPlayer m_number;
    bool swapColor=true;
};

#endif // PLAYER_H
