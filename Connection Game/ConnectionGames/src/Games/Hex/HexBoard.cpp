#include "../../../include/Games/Hex/HexBoard.h"

std::vector<Board::Position> HexBoard::FindStartPointsBlue(const HexBoard& board, Piece::Color playerColor)
{
	std::vector<Board::Position> blueEntryPoints;
	for (int line = 0; line < board.GetBoardSize(); ++line)
	{
		if (board[{line, 0}].has_value()
			&& board[{line, 0}].value().GetColor() == playerColor)
		{
			blueEntryPoints.push_back({ line,0 });
		}
	}
	return blueEntryPoints;
}

std::vector<Board::Position> HexBoard::FindEndPointsBlue(const HexBoard& board, Piece::Color playerColor)
{
	const auto& boardSize = board.GetBoardSize();
	std::vector<Board::Position> blueEndPoints;
	for (int line = 0; line < boardSize; ++line)
	{
		if (board[{line, boardSize - 1}].has_value()
			&& board[{line, boardSize - 1}].value().GetColor() == playerColor)
		{
			blueEndPoints.push_back({ line,boardSize - 1 });
		}
	}
	return blueEndPoints;
}

std::vector<Board::Position> HexBoard::FindStartPointsRed(const HexBoard& board, Piece::Color playerColor)
{
	std::vector<Board::Position> redEntryPoints;
	for (int column = 0; column < board.GetBoardSize(); ++column)
	{
		if (board[{0, column}].has_value()
			&& board[{0, column}].value().GetColor() == playerColor)
		{
			redEntryPoints.push_back({ 0,column });
		}
	}
	return redEntryPoints;
}

std::vector<Board::Position> HexBoard::FindEndPointsRed(const HexBoard& board, Piece::Color playerColor)
{
	const auto& boardSize = board.GetBoardSize();
	std::vector<Board::Position> redEndPoints;
	for (int column = 0; column < boardSize; ++column)
	{
		if (board[{boardSize - 1, column}].has_value()
			&& board[{boardSize - 1, column}].value().GetColor() == playerColor)
		{
			redEndPoints.push_back({ boardSize - 1,column });
		}
	}
	return redEndPoints;
}

bool HexBoard::BFS_Bridge(const HexBoard& board, Piece::Color playerColor)
{
	std::vector<Board::Position> entryPoints;
	std::vector<Board::Position> endPoints;
	if (playerColor == Piece::Color::BLUE)
	{
		entryPoints = FindStartPointsBlue(board, playerColor);
		endPoints = FindEndPointsBlue(board, playerColor);
	}
	else
	{
		entryPoints = FindStartPointsRed(board, playerColor);
		endPoints = FindEndPointsRed(board, playerColor);
	}



	if (!entryPoints.size() || !endPoints.size())
	{
		return false;
	}

	for (int start = 0; start < entryPoints.size(); start++)
	{
		for (int end = 0; end < endPoints.size(); end++)
		{
			if (BFS(board, endPoints[start], endPoints[end], playerColor)) {
				return true;
			}
		}
	}
	return false;
}