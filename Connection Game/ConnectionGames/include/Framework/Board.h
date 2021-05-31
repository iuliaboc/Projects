#pragma once
#include "Piece.h"
#include <vector>
#include <optional>
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


	friend std::ostream& operator<<(std::ostream& out, const Board& board);
    std::optional<Piece>& operator[](const Position& position);
	const std::optional<Piece>& operator[](const Position& position) const;


	bool FullBoard();
	Neighbor GetNeighbor(int row, int column, const Shape& shape) const;
	Neighbor GetNeighborTopLeft(int row, int column, const Shape& shape) const;
	Neighbor GetNeighborTopRight(int row, int column, const Shape& shape) const;
	Neighbor GetNeighborLeft(int row, int column, const Shape& shape) const;
	Neighbor GetNeighborRight(int row, int column, const Shape& shape) const;
	Neighbor GetNeighborBottomLeft(int row, int column, const Shape& shape) const;
	Neighbor GetNeighborBottomRight(int row, int column, const Shape& shape) const;
	bool BFS(const Board& board, Position start, Position end, Piece::Color color);
    
	size_t GetBoardSize() const;
	Shape GetBoardShape() const;

protected:
	const size_t SIZE;
	Shape m_shape;
	std::vector<std::vector<std::optional<Piece>>> m_board;

};
