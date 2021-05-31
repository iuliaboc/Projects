#include "../../../include/Games/Havannah/HavannahBoard.h"

std::vector<Board::Position> HavannahBoard::FindCorners(const HavannahBoard& board, Piece::Color playerColor)
{
	const auto& boardSize = board.GetBoardSize() * 2 - 1;

	std::vector<Board::Position> corners;

	if (board[{0, 0}].has_value()
		&& board[{0, 0}].value().GetColor() == playerColor)
	{
		corners.push_back({ 0, 0 });
	}

	if (board[{boardSize / 2, 0}].has_value()
		&& board[{boardSize / 2, 0}].value().GetColor() == playerColor)
	{
		corners.push_back({ boardSize / 2, 0 });
	}

	if (board[{boardSize - 1, 0}].has_value()
		&& board[{boardSize - 1, 0}].value().GetColor() == playerColor)
	{
		corners.push_back({ boardSize - 1, 0 });
	}

	if (board[{0, boardSize / 2}].has_value()
		&& board[{0, boardSize / 2}].value().GetColor() == playerColor)
	{
		corners.push_back({ 0,boardSize / 2 });
	}

	if (board[{boardSize / 2, boardSize / 2}].has_value()
		&& board[{boardSize / 2, boardSize / 2}].value().GetColor() == playerColor)
	{
		corners.push_back({ boardSize / 2, boardSize / 2 });
	}

	if (board[{boardSize - 1, boardSize / 2}].has_value()
		&& board[{boardSize - 1, boardSize / 2}].value().GetColor() == playerColor)
	{
		corners.push_back({ boardSize - 1, boardSize / 2 });
	}

	return corners;
}

bool HavannahBoard::BFS_Bridge(const HavannahBoard& board, Piece::Color playerColor)
{
	const auto& boardShape = board.GetBoardShape();
	std::vector<Board::Position> corners = FindCorners(board, playerColor);
	std::set<Board::Position> visited;
	std::queue<Board::Position> path;

	auto pushToPath = [&playerColor, &visited, &path](std::pair<Position, Piece::Color> neighbor) {

		const auto& [position, pieceColor] = neighbor;
		if (pieceColor == playerColor && visited.find(position) == visited.end()) path.push(position);
	};

	if (corners.size() < 2)
	{
		return false;
	}

	for (int start = 0; start < corners.size(); ++start)
	{
		path.push(corners.at(start));
		for (int end = start + 1; end < corners.size(); ++end)
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

						if (board.GetNeighborTopLeft(line, column, boardShape).has_value())
						{
							pushToPath(board.GetNeighborTopLeft(line, column, boardShape).value());
						}
						if (board.GetNeighborTopRight(line, column, boardShape).has_value())
						{
							pushToPath(board.GetNeighborTopRight(line, column, boardShape).value());
						}
						if (board.GetNeighborLeft(line, column, boardShape).has_value())
						{
							pushToPath(board.GetNeighborLeft(line, column, boardShape).value());
						}
						if (board.GetNeighborRight(line, column, boardShape).has_value())
						{
							pushToPath(board.GetNeighborRight(line, column, boardShape).value());
						}
						if (board.GetNeighborBottomLeft(line, column, boardShape).has_value())
						{
							pushToPath(board.GetNeighborBottomLeft(line, column, boardShape).value());
						}
						if (board.GetNeighborBottomRight(line, column, boardShape).has_value())
						{
							pushToPath(board.GetNeighborBottomRight(line, column, boardShape).value());
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
	for (int line = 1; line < board.GetBoardSize() - 1; ++line)
	{
		if (board[{line, 0}].has_value()
			&& board[{line, 0}].value().GetColor() == playerColor)
		{
			topLeftEdge.push_back({ line, 0 });
		}
	}
	return topLeftEdge;
}

std::vector<Board::Position> HavannahBoard::GetBottomLeftEdge(const HavannahBoard& board, Piece::Color playerColor)
{
	const auto& boardSize = board.GetBoardSize();
	std::vector<Board::Position> bottomLeftEdge;
	for (int line = boardSize; line < boardSize * 2 - 2; ++line)
	{
		if (board[{line, 0}].has_value()
			&& board[{line, 0}].value().GetColor() == playerColor)
		{
			bottomLeftEdge.push_back({ line, 0 });
		}
	}
	return bottomLeftEdge;
}

std::vector<Board::Position> HavannahBoard::GetTopRightEdge(const HavannahBoard& board, Piece::Color playerColor)
{
	const auto& boardSize = board.GetBoardSize();
	std::vector<Board::Position> topRightEdge;
	for (int line = 1; line < boardSize - 1; ++line)
	{
		if (board[{line, boardSize + line - 1}].has_value()
			&& board[{line, boardSize + line - 1}].value().GetColor() == playerColor)
		{
			topRightEdge.push_back({ line, boardSize + line - 1 });
		}
	}
	return topRightEdge;
}

std::vector<Board::Position> HavannahBoard::GetBottomRightEdge(const HavannahBoard& board, Piece::Color playerColor)
{
	const auto& boardSize = board.GetBoardSize();
	uint8_t column = boardSize;
	std::vector<Board::Position> bottomRightEdge;
	for (int line = boardSize * 2 - 3; line > boardSize -1 ; --line)
	{
		if (board[{line, column}].has_value()
			&& board[{line, column}].value().GetColor() == playerColor)
		{
			bottomRightEdge.push_back({ line, column });
		}
		column++;
	}
	return bottomRightEdge;
}

std::vector<Board::Position> HavannahBoard::GetTopEdge(const HavannahBoard& board, Piece::Color playerColor)
{
	std::vector<Board::Position> topEdge;
	for (int column = 1; column < board.GetBoardSize() - 1; ++column)
	{
		if (board[{0, column}].has_value()
			&& board[{0, column}].value().GetColor() == playerColor)
		{
			topEdge.push_back({ 0, column });
		}
	}
	return topEdge;
}

std::vector<Board::Position> HavannahBoard::GetBottomEdge(const HavannahBoard& board, Piece::Color playerColor)
{
	const auto& boardSize = board.GetBoardSize();
	std::vector<Board::Position> bottomEdge;
	for (int column = 1; column < boardSize - 1; ++column)
	{
		if (board[{boardSize * 2 - 2, column}].has_value()
			&& board[{boardSize * 2 - 2, column}].value().GetColor() == playerColor)
		{
			bottomEdge.push_back({ boardSize * 2 - 2, column });
		}
	}
	return bottomEdge;
}

bool HavannahBoard::BFSBetweenTwoEdges(const HavannahBoard& board, std::vector<Board::Position> edge1, std::vector<Board::Position> edge2, Piece::Color playerColor)
{
	const auto& boardShape = board.GetBoardShape();

	std::set<Board::Position> visited;
	std::queue<Board::Position> path;

	auto pushToPath = [&playerColor, &visited, &path](std::pair<Position, Piece::Color> neighbor) {

		const auto& [position, pieceColor] = neighbor;
		if (pieceColor == playerColor && visited.find(position) == visited.end()) path.push(position);
	};


	for (int start = 0; start < edge1.size(); ++start)
	{
		path.push(edge1.at(start));
		for (int end = 0; end < edge2.size(); ++end)
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


						if (board.GetNeighborTopLeft(line, column, boardShape).has_value())
						{
							pushToPath(board.GetNeighborTopLeft(line, column, boardShape).value());
						}
						if (board.GetNeighborTopRight(line, column, boardShape).has_value())
						{
							pushToPath(board.GetNeighborTopRight(line, column, boardShape).value());
						}
						if (board.GetNeighborLeft(line, column, boardShape).has_value())
						{
							pushToPath(board.GetNeighborLeft(line, column, boardShape).value());
						}
						if (board.GetNeighborRight(line, column, boardShape).has_value())
						{
							pushToPath(board.GetNeighborRight(line, column, boardShape).value());
						}
						if (board.GetNeighborBottomLeft(line, column, boardShape).has_value())
						{
							pushToPath(board.GetNeighborBottomLeft(line, column, boardShape).value());
						}
						if (board.GetNeighborBottomRight(line, column, boardShape).has_value())
						{
							pushToPath(board.GetNeighborBottomRight(line, column, boardShape).value());
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
bool HavannahBoard::areNeighbors(Board::Position position1, Board::Position position2, Piece::Color playerColor, const HavannahBoard& board)
{
	const auto& [line, column] = position1;
	const auto& boardShape = board.GetBoardShape();

	auto isNeighbor = [&playerColor, &position2](std::pair<Position, Piece::Color> neighbor) {

		const auto& [position, pieceColor] = neighbor;
		if (pieceColor == playerColor && position == position2) return true;
	};


	if (board.GetNeighborTopLeft(line, column, boardShape).has_value()) {
		isNeighbor(board.GetNeighborTopLeft(line, column, boardShape).value());
	}
	if (board.GetNeighborTopRight(line, column, boardShape).has_value())
	{
		isNeighbor(board.GetNeighborTopRight(line, column, boardShape).value());
	}
	if (board.GetNeighborLeft(line, column, boardShape).has_value())
	{
		isNeighbor(board.GetNeighborLeft(line, column, boardShape).value());
	}
	if (board.GetNeighborRight(line, column, boardShape).has_value())
	{
		isNeighbor(board.GetNeighborRight(line, column, boardShape).value());
	}
	if (board.GetNeighborBottomLeft(line, column, boardShape).has_value())
	{
		isNeighbor(board.GetNeighborBottomLeft(line, column, boardShape).value());
	}
	if (board.GetNeighborBottomRight(line, column, boardShape).has_value())
	{
		isNeighbor(board.GetNeighborBottomRight(line, column, boardShape).value());
	}
	return false;
}

bool HavannahBoard::CheckFork(const HavannahBoard& board, Piece::Color playerColor)
{
	std::vector<Board::Position> edge1, edge2, edge3;
	int numberOfEdges = 6;
	for (int index1 = 0; index1 < numberOfEdges - 2; ++index1)
	{
		edge1 = FindTheEdge(board, index1, playerColor);
		if (edge1.size())
		{
			for (int index2 = index1 + 1; index2 < numberOfEdges - 1; ++index2)
			{
				edge2 = FindTheEdge(board, index2, playerColor);
				if (edge2.size())
				{
					for (int index3 = index2 + 1; index3 < numberOfEdges; ++index3)
					{
						edge3 = FindTheEdge(board, index3, playerColor);
						if (edge3.size())
						{
							if (BFSBetweenTwoEdges(board, edge1, edge2, playerColor) 
								&& BFSBetweenTwoEdges(board, edge2, edge3, playerColor)
								&& BFSBetweenTwoEdges(board, edge1, edge3, playerColor))
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


bool HavannahBoard::CheckRing(Board::Position lastPlaced, const HavannahBoard& board, Piece::Color playerColor)
{
	const auto& boardShape = board.GetBoardShape();

	std::set<Board::Position> visited;
	std::vector<Board::Position> neighbors;
	std::stack<Board::Position> path;

	auto sameColorNeighbor = [&playerColor, &neighbors](std::pair<Position, Piece::Color> neighbor) {

		const auto& [position, pieceColor] = neighbor;
		if (pieceColor == playerColor) neighbors.push_back(position);
	};


	path.push(lastPlaced);
	visited.insert(lastPlaced);
	while (!path.empty()) {

		Board::Position current = path.top();
		visited.insert(current);
		const auto& [line, column] = current;
		path.pop();

		if (board.GetNeighborTopLeft(line, column, boardShape).has_value()) {
			sameColorNeighbor(board.GetNeighborTopLeft(line, column, boardShape).value());
		}
		if (board.GetNeighborTopRight(line, column, boardShape).has_value())
		{
			sameColorNeighbor(board.GetNeighborTopRight(line, column, boardShape).value());
		}
		if (board.GetNeighborLeft(line, column, boardShape).has_value())
		{
			sameColorNeighbor(board.GetNeighborLeft(line, column, boardShape).value());
		}
		if (board.GetNeighborRight(line, column, boardShape).has_value())
		{
			sameColorNeighbor(board.GetNeighborRight(line, column, boardShape).value());
		}
		if (board.GetNeighborBottomLeft(line, column, boardShape).has_value())
		{
			sameColorNeighbor(board.GetNeighborBottomLeft(line, column, boardShape).value());
		}
		if (board.GetNeighborBottomRight(line, column, boardShape).has_value())
		{
			sameColorNeighbor(board.GetNeighborBottomRight(line, column, boardShape).value());
		}



		if (neighbors.size() == 2) {
			for (int i = 0; i < neighbors.size() - 1; ++i) {
				for (int j = i + 1; j < neighbors.size(); ++j) {
					if (areNeighbors(neighbors[i], neighbors[j], playerColor, board)) {
						return false;
					}
				}

			}


			bool found = false;
			for (int i = 0; i < neighbors.size(); ++i) {
				if (neighbors[i] == lastPlaced) found = true;
				if (visited.find(neighbors[i]) == visited.end()) {
					path.push(neighbors[i]);

				}
			}
			if (found && visited.size() >= 6) {
				return true;
			}
		}
		else {
			return false;
		}
		neighbors.clear();
	}
	return false;

}


