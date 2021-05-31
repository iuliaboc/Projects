#ifndef BOARD_H
#define BOARD_H


#include "piece.h"
#include <vector>
#include <optional>
#include<ostream>
#include<set>
#include<queue>

class Board
{

public:
    enum class Shape :uint8_t
    {
        HEXAGON,
        PARALLELOGRAM,
        TRIANGLE
    };
public:
    using Position = std::pair<uint8_t, uint8_t>;
    using Neighbor = std::optional<std::pair<Position, Piece::Color>>;
public:
    Board(size_t constant, const Shape& shape);
    size_t GetSize() const noexcept;

    friend std::ostream& operator<<(std::ostream& out, const Board& board);
    std::optional<Piece>& operator[](const Position& position);
    const std::optional<Piece>& operator[](const Position& position) const;


    Neighbor GetNeighborTopLeft(int row, int column, const Shape& shape) const;
    Neighbor GetNeighborTopRight(int row, int column, const Shape& shape) const;
    Neighbor GetNeighborLeft(int row, int column, const Shape& shape) const;
    Neighbor GetNeighborRight(int row, int column, const Shape& shape) const;
    Neighbor GetNeighborBottomLeft(int row, int column, const Shape& shape) const;
    Neighbor GetNeighborBottomRight(int row, int column, const Shape& shape) const;
    bool BFS(const Board& board, Position start, Position end, Piece::Color color);
    std::vector<std::vector<std::optional<Piece>>> GetBoard();

    void ClearBoard();

protected:
    const size_t SIZE;
    Shape m_shape;
    std::vector<std::vector<std::optional<Piece>>> m_board;

};
#endif // BOARD_H
