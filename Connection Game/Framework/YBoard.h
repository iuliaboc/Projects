#ifndef YBOARD_H
#define YBOARD_H

#pragma once
#include"board.h"
#include<set>
#include<queue>

class YBoard : public Board
{
public:
    size_t boardSize = 13;
    YBoard() : Board(13, Shape::TRIANGLE) {}



   /* bool BFS_CornerToOpositEdge(const YBoard& board, Piece::Color playerColor);

    bool VerifyStarts(const YBoard& board, std::vector<Board::Position>& corners, Piece::Color playerColor);
    bool VerifyEnds(const YBoard& board, std::vector<Board::Position>& endEdge, Board::Position start, Piece::Color playerColor);

    std::vector<Board::Position> FindPieceOnEdge(int line, int column, int edge, Piece::Color playerColor);
    bool BFS_AllEdges(const YBoard& board, Piece::Color playerColor);
    */
};

#endif // YBOARD_H
