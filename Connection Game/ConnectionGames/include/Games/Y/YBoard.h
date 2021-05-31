#pragma once
#include"../../Framework/Board.h"
#include<set>
#include<queue>

class YBoard : public Board
{
public:
	YBoard() : Board(13, Shape::TRIANGLE) {}

	bool BFS_CornerToOpositEdge(const YBoard& board, Piece::Color playerColor);

	bool VerifyStarts(const YBoard& board, std::vector<Board::Position>& corners, Piece::Color playerColor);
	bool VerifyEnds(const YBoard& board, std::vector<Board::Position>& endEdge, Board::Position start, Piece::Color playerColor);

	std::vector<Board::Position> FindPieceOnEdge(const YBoard& board, int line, int column, int edge, Piece::Color playerColor);
	bool BFS_AllEdges(const YBoard& board, Piece::Color playerColor);
};


