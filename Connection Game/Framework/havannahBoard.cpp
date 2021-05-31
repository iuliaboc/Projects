#include "havannahBoard.h"
/*
std::vector<Board::Position> HavannahBoard::FindCorners(const HavannahBoard& board, Piece::Color playerColor)
{
    std::vector<Board::Position> corners;

    if (board.m_board.at(0).at(0).has_value()
        && board.m_board.at(0).at(0).value().GetColor() == playerColor)
    {
        corners.push_back(std::make_pair(0, 0));
    }

    if (board.m_board.at(board.m_board.at(0).size() - 1).at(0).has_value()
        && board.m_board.at(board.m_board.at(0).size() - 1).at(0).value().GetColor() == playerColor)
    {
        corners.push_back(std::make_pair(board.m_board.at(0).size() - 1, 0));
    }

    if (board.m_board.at(board.m_board.size() - 1).at(0).has_value()
        && board.m_board.at(board.m_board.size() - 1).at(0).value().GetColor() == playerColor)
    {
        corners.push_back(std::make_pair(board.m_board.size() - 1, 0));
    }

    if (m_board.at(0).at(board.m_board.at(0).size() - 1).has_value()
        && m_board.at(0).at(board.m_board.at(0).size() - 1).value().GetColor() == playerColor)
    {
        corners.push_back(std::make_pair(0, board.m_board.at(0).size() - 1));
    }

    if (board.m_board.at(board.m_board.at(0).size() - 1).at(board.m_board.size() - 1).has_value()
        && board.m_board.at(board.m_board.at(0).size() - 1).at(board.m_board.size() - 1).value().GetColor() == playerColor)
    {
        corners.push_back(std::make_pair(board.m_board.at(0).size() - 1, board.m_board.size() - 1));
    }

    if (board.m_board.at(board.m_board.size() - 1).at(board.m_board.at(0).size() - 1).has_value()
        && board.m_board.at(board.m_board.size() - 1).at(board.m_board.at(0).size() - 1).value().GetColor() == playerColor)
    {
        corners.push_back(std::make_pair(board.m_board.size() - 1, board.m_board.at(0).size() - 1));
    }

    return corners;
}

bool HavannahBoard::BFS_Bridge(const HavannahBoard& board, Piece::Color playerColor)
{
    std::vector<Board::Position> corners = FindCorners(board, playerColor);
    std::set<Board::Position> visited;
    std::queue<Board::Position> path;


    if (corners.size() < 2)
    {
        return false;
    }

    for (int start = 0; start < corners.size(); start++)
    {
        path.push(corners.at(start));
        for (int end = start + 1; end < corners.size(); end++)
        {
            Board::Position posEnd = corners.at(end);
            while (!path.empty())
            {
                Board::Position current = path.front();
                int line = current.first;
                int column = current.second;
                path.pop();

                if (current == posEnd) {
                    return true;
                }
                else {


                    if (visited.find(current) == visited.end()) {

                        visited.insert(current);


                        if (board.GetNeighborTopLeft(line, column, Board::Shape::HEXAGON).has_value())
                        {
                            const auto& [position, color] = board.GetNeighborTopLeft(line, column, Board::Shape::TRIANGLE).value();
                            if (color == playerColor && visited.find(position) == visited.end())
                            {
                                path.push(position);
                            }

                        }
                        if (board.GetNeighborTopRight(line, column, Board::Shape::HEXAGON).has_value())
                        {
                            const auto& [position, color] = board.GetNeighborTopRight(line, column, Board::Shape::TRIANGLE).value();
                            if (color == playerColor && visited.find(position) == visited.end())
                            {
                                path.push(position);
                            }
                        }

                        if (board.GetNeighborLeft(line, column, Board::Shape::HEXAGON).has_value())
                        {
                            const auto& [position, color] = board.GetNeighborLeft(line, column, Board::Shape::TRIANGLE).value();
                            if (color == playerColor && visited.find(position) == visited.end())
                            {
                                path.push(position);
                            }
                        }
                        if (board.GetNeighborRight(line, column, Board::Shape::HEXAGON).has_value())
                        {
                            const auto& [position, color] = board.GetNeighborRight(line, column, Board::Shape::TRIANGLE).value();
                            if (color == playerColor && visited.find(position) == visited.end())
                            {
                                path.push(position);
                            }
                        }
                        if (board.GetNeighborBottomLeft(line, column, Board::Shape::HEXAGON).has_value())
                        {
                            const auto& [position, color] = board.GetNeighborBottomLeft(line, column, Board::Shape::TRIANGLE).value();
                            if (color == playerColor && visited.find(position) == visited.end())
                            {
                                path.push(position);
                            }
                        }
                        if (board.GetNeighborBottomRight(line, column, Board::Shape::HEXAGON).has_value())
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
    }
    return false;
}

std::vector<Board::Position> HavannahBoard::GetTopLeftEdge(const HavannahBoard& board, Piece::Color playerColor)
{
    std::vector<Board::Position> topLeftEdge;
    for (int index = 1; index < board.m_board.size() / 2; index++)
    {
        if (board.m_board.at(index).at(0).has_value()
            && board.m_board.at(index).at(0).value().GetColor() == playerColor)
        {
            topLeftEdge.push_back(std::make_pair(index, 0));
        }
    }
    return topLeftEdge;
}

std::vector<Board::Position> HavannahBoard::GetBottomLeftEdge(const HavannahBoard& board, Piece::Color playerColor)
{
    std::vector<Board::Position> bottomLeftEdge;
    for (int index = board.m_board.size() / 2 + 1; index < board.m_board.size() - 1; index++)
    {
        if (board.m_board.at(index).at(0).has_value()
            && board.m_board.at(index).at(0).value().GetColor() == playerColor)
        {
            bottomLeftEdge.push_back(std::make_pair(index, 0));
        }
    }
    return bottomLeftEdge;
}

std::vector<Board::Position> HavannahBoard::GetTopRightEdge(const HavannahBoard& board, Piece::Color playerColor)
{
    std::vector<Board::Position> topRightEdge;
    for (int index = 1; index < board.m_board.size() / 2; index++)
    {
        if (board.m_board.at(index).at(board.m_board.at(index).size() - 1).has_value()
            && board.m_board.at(index).at(board.m_board.at(index).size() - 1).value().GetColor() == playerColor)
        {
            topRightEdge.push_back(std::make_pair(index, board.m_board.at(index).size() - 1));
        }
    }
    return topRightEdge;
}

std::vector<Board::Position> HavannahBoard::GetBottomRightEdge(const HavannahBoard& board, Piece::Color playerColor)
{
    std::vector<Board::Position> bottomRightEdge;
    for (int index = board.m_board.size() / 2 + 1; index < board.m_board.size() - 1; index++)
    {
        if (board.m_board.at(index).at(board.m_board.at(index).size() - 1).has_value()
            && board.m_board.at(index).at(board.m_board.at(index).size() - 1).value().GetColor() == playerColor)
        {
            bottomRightEdge.push_back(std::make_pair(index, board.m_board.at(index).size() - 1));
        }
    }
    return bottomRightEdge;
}

std::vector<Board::Position> HavannahBoard::GetTopEdge(const HavannahBoard& board, Piece::Color playerColor)
{
    std::vector<Board::Position> topEdge;
    for (int index = 1; index < board.m_board.at(0).size() - 1; index++)
    {
        if (board.m_board.at(0).at(index).has_value()
            && board.m_board.at(0).at(index).value().GetColor() == playerColor)
        {
            topEdge.push_back(std::make_pair(0, index));
        }
    }
    return topEdge;
}

std::vector<Board::Position> HavannahBoard::GetBottomEdge(const HavannahBoard& board, Piece::Color playerColor)
{
    std::vector<Board::Position> bottomEdge;
    for (int index = 1; index < board.m_board.at(0).size() - 1; index++)
    {
        if (board.m_board.at(board.m_board.size() - 1).at(index).has_value()
            && board.m_board.at(board.m_board.size() - 1).at(index).value().GetColor() == playerColor)
        {
            bottomEdge.push_back(std::make_pair(board.m_board.size() - 1, index));
        }
    }
    return bottomEdge;
}

bool HavannahBoard::BFSBetweenTwoEdges(const HavannahBoard& board, std::vector<Board::Position> edge1, std::vector<Board::Position> edge2, Piece::Color playerColor)
{
    std::set<Board::Position> visited;
    std::queue<Board::Position> path;

    for (int start = 0; start < edge1.size(); start++)
    {
        path.push(edge1.at(start));
        for (int end = 0; end < edge2.size(); end++)
        {
            Board::Position posEnd = edge2.at(end);
            while (!path.empty())
            {
                Board::Position current = path.front();
                int line = current.first;
                int column = current.second;
                path.pop();

                if (current == posEnd) {
                    return true;
                }
                else {


                    if (visited.find(current) == visited.end()) {

                        visited.insert(current);


                        if (board.GetNeighborTopLeft(line, column, Board::Shape::HEXAGON).has_value())
                        {
                            const auto& [position, color] = board.GetNeighborTopLeft(line, column, Board::Shape::HEXAGON).value();
                            if (color == playerColor && visited.find(position) == visited.end())
                            {
                                path.push(position);
                            }

                        }
                        if (board.GetNeighborTopRight(line, column, Board::Shape::HEXAGON).has_value())
                        {
                            const auto& [position, color] = board.GetNeighborTopRight(line, column, Board::Shape::HEXAGON).value();
                            if (color == playerColor && visited.find(position) == visited.end())
                            {
                                path.push(position);
                            }
                        }

                        if (board.GetNeighborLeft(line, column, Board::Shape::HEXAGON).has_value())
                        {
                            const auto& [position, color] = board.GetNeighborLeft(line, column, Board::Shape::HEXAGON).value();
                            if (color == playerColor && visited.find(position) == visited.end())
                            {
                                path.push(position);
                            }
                        }
                        if (board.GetNeighborRight(line, column, Board::Shape::HEXAGON).has_value())
                        {
                            const auto& [position, color] = board.GetNeighborRight(line, column, Board::Shape::HEXAGON).value();
                            if (color == playerColor && visited.find(position) == visited.end())
                            {
                                path.push(position);
                            }
                        }
                        if (board.GetNeighborBottomLeft(line, column, Board::Shape::HEXAGON).has_value())
                        {
                            const auto& [position, color] = board.GetNeighborBottomLeft(line, column, Board::Shape::HEXAGON).value();
                            if (color == playerColor && visited.find(position) == visited.end())
                            {
                                path.push(position);
                            }
                        }
                        if (board.GetNeighborBottomRight(line, column, Board::Shape::HEXAGON).has_value())
                        {
                            const auto& [position, color] = board.GetNeighborRight(line, column, Board::Shape::HEXAGON).value();
                            if (color == playerColor && visited.find(position) == visited.end())
                            {
                                path.push(position);
                            }
                        }
                    }

                }
            }
        }
    }

    return false;
}

std::vector<Board::Position> HavannahBoard::FindTheEdge(const HavannahBoard& board, int edge, Piece::Color playerColor)
{
    switch (edge)
    {
    case 0:
        return GetTopLeftEdge(board, playerColor);

    case 1:
        return GetTopEdge(board, playerColor);

    case 2:
        return GetTopRightEdge(board, playerColor);

    case 3:
        return GetBottomRightEdge(board, playerColor);

    case 4:
        return GetBottomEdge(board, playerColor);

    case 5:
        return GetBottomLeftEdge(board, playerColor);

    default:
        break;
    }
}

bool HavannahBoard::CheckFork(const HavannahBoard& board, Piece::Color playerColor)
{
    std::vector<Board::Position> edge1, edge2, edge3;
    int numberOfEdges = 6;
    for (int index1 = 0; index1 < numberOfEdges - 2; index1++)
    {
        edge1 = FindTheEdge(board, index1, playerColor);
        if (edge1.size())
        {
            for (int index2 = index1 + 1; index2 < numberOfEdges - 1; index2++)
            {
                edge2 = FindTheEdge(board, index2, playerColor);
                if (edge2.size())
                {
                    for (int index3 = index2 + 1; index3 < numberOfEdges; index3++)
                    {
                        edge3 = FindTheEdge(board, index3, playerColor);
                        if (edge3.size())
                        {
                            if (BFSBetweenTwoEdges(board, edge1, edge2, playerColor) && BFSBetweenTwoEdges(board, edge2, edge3, playerColor))
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}


bool HavannahBoard::CheckRing(Board::Position position, const HavannahBoard& board)
{
    //TODO MORE
    bool ok = false;
    const auto& [line, column] = position;
    std::vector<Board::Neighbor> neighbors;
    neighbors.push_back(board.GetNeighborTopLeft(line , column, Board::Shape::HEXAGON));
    neighbors.push_back(board.GetNeighborTopRight(line, column, Board::Shape::HEXAGON));
    neighbors.push_back(board.GetNeighborLeft(line, column, Board::Shape::HEXAGON));
    neighbors.push_back(board.GetNeighborRight(line, column, Board::Shape::HEXAGON));
    neighbors.push_back(board.GetNeighborBottomLeft(line, column, Board::Shape::HEXAGON));
    neighbors.push_back(board.GetNeighborBottomRight(line, column, Board::Shape::HEXAGON));
    for (const auto& element : neighbors)
    {
        if (element.has_value())
        {
            const auto& [pos, color] = element.value();
            if (color == Piece::Color::NONE)
            {
                ok = true;
                break;
            }
        }
    }
    if (Board::BFS(board, position, position, Piece::Color::BLUE) && ok==true) return true;
    if (Board::BFS(board, position, position, Piece::Color::RED) && ok==true) return true;
    return false;
}
*/
