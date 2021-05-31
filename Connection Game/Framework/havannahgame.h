#ifndef HAVANNAHGAME_H
#define HAVANNAHGAME_H

#include"havannahBoard.h"

class HavannahGame: public HavannahBoard
{
public:
    HavannahGame();

    std::vector<Board::Position> FindCorners(const HavannahBoard& board, Piece::Color playerColor);
    bool BFS_Bridge(const HavannahBoard& board, Piece::Color playerColor);

    std::vector<Board::Position> GetTopLeftEdge(const HavannahBoard& board, Piece::Color playerColor);
    std::vector<Board::Position> GetBottomLeftEdge(const HavannahBoard& board, Piece::Color playerColor);
    std::vector<Board::Position> GetTopRightEdge(const HavannahBoard& board, Piece::Color playerColor);
    std::vector<Board::Position> GetBottomRightEdge(const HavannahBoard& board, Piece::Color playerColor);
    std::vector<Board::Position> GetTopEdge(const HavannahBoard& board, Piece::Color playerColor);
    std::vector<Board::Position> GetBottomEdge(const HavannahBoard& board, Piece::Color playerColor);

    bool BFSBetweenTwoEdges(const HavannahBoard& board, std::vector<Board::Position> edge1, std::vector<Board::Position> edge2, Piece::Color playerColor);
    std::vector<Board::Position> FindTheEdge(const HavannahBoard& board, int edge, Piece::Color playerColor);
    bool CheckFork(const HavannahBoard& board, Piece::Color playerColor);


    bool CheckRing(Board::Position position, const HavannahBoard& board);

    bool CheckIfWon(const HavannahBoard& board, Piece::Color playerColor);
};

#endif // HAVANNAHGAME_H
