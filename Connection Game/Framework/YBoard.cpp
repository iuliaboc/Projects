#include "YBoard.h"


/*
bool YBoard::BFS_CornerToOpositEdge(const YBoard& board, Piece::Color playerColor)

{
    std::set<Board::Position> visited;
    std::queue<Board::Position> path;

    Board::Position start;
    std::vector<Board::Position>corners;

    std::vector<Board::Position> endEdge;


    if (VerifyStarts(board, corners, playerColor))
    {
        for (int indexCorners = 0; indexCorners < corners.size(); indexCorners++)
        {
            start = corners.at(indexCorners);
            if (VerifyEnds(board, endEdge, start, playerColor))
            {
                path.push(start);
                while (!path.empty()) {

                    Board::Position current = path.front();
                    int line = current.first;
                    int column = current.second;
                    path.pop();
                    bool end = false;
                    for (int indexEnd = 0; indexEnd < endEdge.size() && end == false; indexEnd++)
                    {
                        if (current == endEdge.at(indexEnd))
                        {
                            end = true;
                        }
                    }
                    if (end)
                    {
                        return true;
                    }
                    else
                    {
                        if (visited.find(current) == visited.end())
                        {

                            visited.insert(current);

                            if (board.GetNeighborTopLeft(line, column, Board::Shape::TRIANGLE).has_value())
                            {
                                const auto& [position, color] = board.GetNeighborTopLeft(line, column, Board::Shape::TRIANGLE).value();
                                if (color == playerColor && visited.find(position) == visited.end())
                                {
                                    path.push(position);
                                }

                            }
                            if (board.GetNeighborTopRight(line, column, Board::Shape::TRIANGLE).has_value())
                            {
                                const auto& [position, color] = board.GetNeighborTopRight(line, column, Board::Shape::TRIANGLE).value();
                                if (color == playerColor && visited.find(position) == visited.end())
                                {
                                    path.push(position);
                                }
                            }

                            if (board.GetNeighborLeft(line, column, Board::Shape::TRIANGLE).has_value())
                            {
                                const auto& [position, color] = board.GetNeighborLeft(line, column, Board::Shape::TRIANGLE).value();
                                if (color == playerColor && visited.find(position) == visited.end())
                                {
                                    path.push(position);
                                }
                            }
                            if (board.GetNeighborRight(line, column, Board::Shape::TRIANGLE).has_value())
                            {
                                const auto& [position, color] = board.GetNeighborRight(line, column, Board::Shape::TRIANGLE).value();
                                if (color == playerColor && visited.find(position) == visited.end())
                                {
                                    path.push(position);
                                }
                            }
                            if (board.GetNeighborBottomLeft(line, column, Board::Shape::TRIANGLE).has_value())
                            {
                                const auto& [position, color] = board.GetNeighborBottomLeft(line, column, Board::Shape::TRIANGLE).value();
                                if (color == playerColor && visited.find(position) == visited.end())
                                {
                                    path.push(position);
                                }
                            }
                            if (board.GetNeighborBottomRight(line, column, Board::Shape::TRIANGLE).has_value())
                            {
                                const auto& [position, color] = board.GetNeighborBottomRight(line, column, Board::Shape::TRIANGLE).value();
                                if (color == playerColor && visited.find(position) == visited.end())
                                {
                                    path.push(position);
                                }
                            }
                        }
                    }

                }
            }
            endEdge.clear();
        }
    }

    return false;
}

bool YBoard::VerifyStarts(const YBoard& board, std::vector<Board::Position>& corners, Piece::Color playerColor)
{
    bool verify = false;
    if (m_board.at(0).at(0).has_value()
        && m_board.at(0).at(0).value().GetColor() == playerColor)
    {
        verify = true;
        corners.push_back(std::make_pair(0, 0));
    }
    if (m_board.at(boardSize - 1).at(0).has_value()
        && m_board.at(boardSize - 1).at(0).value().GetColor() == playerColor)
    {
        verify = true;
        corners.push_back(std::make_pair(boardSize - 1, 0));
    }
    if (m_board.at(boardSize - 1).at(boardSize - 1).has_value()
        && m_board.at(boardSize - 1).at(boardSize - 1).value().GetColor() == playerColor)
    {
        verify = true;
        corners.push_back(std::make_pair(boardSize - 1, boardSize - 1));
    }
    if (verify)
    {
        return true;
    }
    return false;
}

bool YBoard::VerifyEnds(const YBoard& board, std::vector<Board::Position>& endEdge, Board::Position start, Piece::Color playerColor)
{
    if (start.first == 0 && start.second == 0)
    {
        int row = boardSize - 1;
        for (int column = 0; column < boardSize; column++)
        {
            if (m_board.at(row).at(column).has_value() && m_board.at(row).at(column).value().GetColor() == playerColor)
            {
                endEdge.push_back(std::make_pair(row, column));
                return true;
            }
        }

    }
    if (start.first == boardSize - 1 && start.second == 0)
    {
        for (int row = 0; row < boardSize; row++)
        {
            if (m_board.at(row).at(row).has_value() && m_board.at(row).at(row).value().GetColor() == playerColor)
            {
                endEdge.push_back(std::make_pair(row, row));
                return true;
            }
        }

    }
    if (start.first == boardSize - 1 && start.second == boardSize - 1)
    {
        int column = 0;
        for (int row = 0; row < boardSize; row++)
        {
            if (m_board.at(row).at(column).has_value() && m_board.at(row).at(column).value().GetColor() == playerColor)
            {
                endEdge.push_back(std::make_pair(row, column));
                return true;
            }
        }

    }
    return false;
}

std::vector<Board::Position> YBoard::FindPieceOnEdge(int line, int column, int edge, Piece::Color playerColor)
{
    std::vector<Board::Position> out;
    Board::Position auxiliar;
    if (edge == 1)
    {
        for (int index = line; index < boardSize; index++)
        {
            if (m_board.at(index).at(column).has_value()
                && m_board.at(index).at(column).value().GetColor() == playerColor)
            {
                auxiliar.first = index;
                auxiliar.second = column;
                out.push_back(auxiliar);
            }
        }
        return out;
    }
    if (edge == 2)
    {
        for (int index = column; index < boardSize; index++)
        {
            if (m_board.at(line).at(index).has_value()
                && m_board.at(line).at(index).value().GetColor() == playerColor)
            {
                auxiliar.first = line;
                auxiliar.second = index;
                out.push_back(auxiliar);
            }
        }
        return out;
    }
    if (edge == 3)
    {
        for (int index = line; index < boardSize; index++)
        {
            if (m_board.at(index).at(index).has_value()
                && m_board.at(index).at(index).value().GetColor() == playerColor)
            {
                auxiliar.first = index;
                auxiliar.second = index;
                out.push_back(auxiliar);
            }
        }
        return out;
    }
}



bool YBoard::BFS_AllEdges(const YBoard& board, Piece::Color playerColor)
{
    std::vector<Board::Position> edge1, edge2, end;
    edge1 = FindPieceOnEdge(1, 0, 1, playerColor);
    if (edge1.size() == 0)
    {
        return false;
    }

    edge2 = FindPieceOnEdge(boardSize - 1, 1, 2, playerColor);
    if (edge2.size() == 0)
    {
        return false;
    }

    end = FindPieceOnEdge(1, 1, 3, playerColor);
    if (end.size() == 0)
    {
        return false;
    }

    for (int indexFinish = 0; indexFinish < end.size(); indexFinish++)
    {
        for (int indexEdge1 = 0; indexEdge1 < edge1.size(); indexEdge1++)
        {
            if (BFS(board, edge1.at(indexEdge1), end.at(indexFinish), playerColor))
            {
                for (int indexEdge2 = 0; indexEdge2 < edge2.size(); indexEdge2++)
                {
                    if (BFS(board, edge2.at(indexEdge2), end.at(indexFinish), playerColor))
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}
*/
