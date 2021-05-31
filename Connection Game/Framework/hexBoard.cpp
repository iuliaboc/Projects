#include"hexBoard.h"

HexBoard::HexBoard() :Board(11, Shape::PARALLELOGRAM)
{
    int low = 0, high = SIZE - 1;
    for (int index = 0; index < SIZE; ++index)
    {
        blueEntryPoints.push_back(std::make_pair(index, low));
        blueExitPoints.push_back(std::make_pair(index, high));
        redEntryPoints.push_back(std::make_pair(low, index));
        redExitPoints.push_back(std::make_pair(high, index));
    }
}
/*
std::optional<std::string> HexBoard::CheckBridge(const HexBoard& board, const Player& player)
{
    if (player.GetColor() == Piece::Color::BLUE) {

        for (auto& blueEntryPoint : blueEntryPoints) {
            if (board[blueEntryPoint].has_value() && (board[blueEntryPoint].value().GetColor() == Piece::Color::BLUE)) {

                for (auto& blueExitPoint : blueExitPoints) {
                    if (board[blueExitPoint].has_value() && (board[blueExitPoint].value().GetColor() == Piece::Color::BLUE)) {

                        if (Board::BFS(board, blueEntryPoint, blueExitPoint, Piece::Color::BLUE)) {
                            return "Blue won";
                        }

                    }
                }
            }
        }
        return std::nullopt;
    }
    else {

        for (auto& redEntryPoint : redEntryPoints) {
            if (board[redEntryPoint].has_value() && (board[redEntryPoint].value().GetColor() == Piece::Color::RED)) {
                for (auto& redExitPoint : redExitPoints) {
                    if (board[redExitPoint].has_value() && (board[redExitPoint].value().GetColor() == Piece::Color::RED)) {

                        if (Board::BFS(board, redEntryPoint, redExitPoint, Piece::Color::RED)) {
                            return "Red Won";


                        }
                    }
                }
            }
        }

        return std::nullopt;

    }
}
*/
