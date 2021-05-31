#ifndef YGAME_H
#define YGAME_H

#include"YBoard.h"
#include"yframe.h"
#include"yWindow.h"

class YGame:public YBoard, public YFrame
{
public:
    YGame();

    bool BFS_CornerToOpositEdge(const YBoard& board, Piece::Color playerColor);

    bool VerifyStarts(const YBoard& board, std::vector<Board::Position>& corners, Piece::Color playerColor);
    bool VerifyEnds(const YBoard& board, std::vector<Board::Position>& endEdge, Board::Position start, Piece::Color playerColor);

    std::vector<Board::Position> FindPieceOnEdge(int line, int column, int edge, Piece::Color playerColor);
    bool BFS_AllEdges(const YBoard& board, Piece::Color playerColor);

    bool CheckIfWon(const YBoard& board, Piece::Color playerColor);

    void Run();
};

#endif // YGAME_H
