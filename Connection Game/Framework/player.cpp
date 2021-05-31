#include "player.h"

std::ostream& operator<<(std::ostream& out, const Player& player)
{
    return out << player.m_name;
}

Player::Player(const std::string& name, Piece::Color color, NrPlayer number) :m_name(name), m_color(color), m_number(number)
{
    if (number == NrPlayer::FIRST) { swapColor = false; }
}

Board::Position Player::PlacePiece(Board::Position position, Board& board)
{
    Piece piece(m_color);


    auto& optionalPiece = board[position];

    if (optionalPiece.has_value()) {

        if (swapColor)
        {
            optionalPiece = std::move(piece);
            swapColor = false;
        }
        else
        {
            std::cout << "That position is occupied by another piece.";
        }

    }
    else {
        if (m_number == NrPlayer::SECOND)
        {
            swapColor = false;
        }
        optionalPiece = std::move(piece);
        return position;
    }

}

Piece::Color Player::GetColor() const noexcept
{
    return m_color;
}

Player::NrPlayer Player::GetNrPlayer() const noexcept
{
    return m_number;
}
