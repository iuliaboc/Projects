#pragma once
#include"../../Framework/Board.h"
#include"../../Framework/Piece.h"
#include"../../Framework/Player.h"
#include<set>
#include<queue>
#include<iostream>

class HexBoard :  public Board
{
public:
	HexBoard() :Board(11, Shape::PARALLELOGRAM) {};

	std::vector<Board::Position> FindStartPointsBlue(const HexBoard& board, Piece::Color playerColor);
	std::vector<Board::Position> FindEndPointsBlue(const HexBoard& board, Piece::Color playerColor);
	std::vector<Board::Position> FindStartPointsRed(const HexBoard& board, Piece::Color playerColor);
	std::vector<Board::Position> FindEndPointsRed(const HexBoard& board, Piece::Color playerColor);

	bool BFS_Bridge(const HexBoard& board, Piece::Color playerColor);
};

