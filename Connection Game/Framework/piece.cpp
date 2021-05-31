#include "piece.h"


Piece::Piece()
    :Piece(Color::NONE)
{
}

Piece::Piece(Color color)
    :m_color{color}
{
}

Piece::Piece(const Piece& piece)
{
    *this = piece;
}

Piece::Piece(Piece&& piece) noexcept
{
    *this = std::move(piece);
}

Piece& Piece::operator=(const Piece& piece)
{
    if (this != &piece)
    {
        m_color = piece.m_color;
    }
    return *this;
}

Piece& Piece::operator=(Piece&& piece) noexcept
{
    if (this != &piece)
    {
        m_color = piece.m_color;
        new(&piece) Piece();
    }
    return *this;
}

Piece::Color Piece::GetColor() const
{
    return m_color;
}

std::ostream& operator<<(std::ostream& out, const Piece& piece)
{
    return out << static_cast<int>(piece.m_color);

}
