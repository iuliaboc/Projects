#ifndef PIECE_H
#define PIECE_H
#include<QColor>
#include<cstdint>
#include<ostream>

class Piece
{
public:
    enum class Color :uint8_t
    {
        NONE,
        RED = 1,
        BLUE = 2
    };
    constexpr QColor colorToQColor(const Color& color) noexcept
    {
        switch(color)
        {
            case Color::RED:
                return Qt::red;

            case Color::BLUE:
                return Qt::blue;

            case Color::NONE:
            default:
                return Qt::white;

        }
    }
public:
    Piece();
    Piece(Color color);
    Piece(const Piece& piece);
    Piece(Piece&& piece) noexcept;
    Piece& operator=(const Piece& piece);
    Piece& operator=(Piece&& piece) noexcept;
    ~Piece() = default;

    Color GetColor() const;

    friend std::ostream& operator<<(std::ostream& out, const Piece& piece);
private:
    Color m_color : 2;
};

#endif // PIECE_H
