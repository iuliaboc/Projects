#include "../../include/Framework/Board.h"

Board::Board(size_t constant, const Shape& shape)
	:SIZE(constant), m_shape(shape)
{
	switch (shape)
	{
	case Shape::HEXAGON:
		m_board.resize(SIZE * 2 - 1);
		int columns;
		for (int index = 0; index < SIZE * 2 - 1; ++index) {
			if (index < SIZE)
			{
				columns = SIZE + index;
				m_board.at(index).resize(columns);
			}
			else {
				m_board.at(index).resize(--columns);
			}
		}
		break;
	case Shape::PARALLELOGRAM:
		m_board.resize(SIZE);
		for (int index = 0; index < SIZE; ++index) {
			m_board.at(index).resize(SIZE);
		}
		break;
	case Shape::TRIANGLE:
		m_board.resize(SIZE);
		for (int index = 0; index < SIZE; ++index) {
			m_board.at(index).resize(index + 1);
		}
		break;
	default:
		throw "Invalid shape.";
		break;
	}
}

const char emptyBoardCell[] = "*";
std::ostream& operator<<(std::ostream& out, const Board& board)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string spacing = "";
	out << '\n';
	
	if (board.m_shape == Board::Shape::PARALLELOGRAM) {
		out.width(5);
		SetConsoleTextAttribute(hConsole, 4);
		for (int index = 0; index < board.SIZE; ++index) {
			out << "R ";
		}
		out << '\n';
		out << '\n';
		SetConsoleTextAttribute(hConsole, 7);
	}

	for (int line = 0; line < board.m_board.size(); ++line) {
		switch (board.m_shape)
		{
		case Board::Shape::HEXAGON:
			spacing.resize(board.m_board.at(board.m_board.size() / 2).size() - board.m_board.at(line).size(), ' ');
			break;
		case Board::Shape::PARALLELOGRAM:
			spacing += ' ';
			break;
		case Board::Shape::TRIANGLE:
			spacing.resize(board.m_board.size() - board.m_board.at(line).size(), ' ');
			break;
		}

		out << spacing;

		if (board.m_shape == Board::Shape::PARALLELOGRAM) {
			SetConsoleTextAttribute(hConsole, 1);
			out << "B  ";
		}
		for (int column = 0; column < board.m_board.at(line).size(); ++column) {

			if (auto& optPiece = board[{line, column}]; optPiece) {
				out << optPiece.value() << " ";
			}
			else {
				SetConsoleTextAttribute(hConsole, 7);
				out << emptyBoardCell << " ";
			}

			if (column == board.m_board.at(line).size() - 1 && (board.m_shape == Board::Shape::PARALLELOGRAM)) {
				SetConsoleTextAttribute(hConsole, 1);
				out << "  B";
			}

		}

		out << '\n';


	}

	if (board.m_shape == Board::Shape::PARALLELOGRAM) {
		out << '\n';
		out.width(17);
		SetConsoleTextAttribute(hConsole, 4);
		for (int i = 0; i < board.SIZE; ++i) {
			out << "R ";
		}
		out << '\n';
		SetConsoleTextAttribute(hConsole, 7);
	}

	return out;
}
std::optional<Piece>& Board::operator[](const Position& position)
{
	const auto& [line, column] = position;
	if (line < m_board.size() && column < m_board.at(line).size())
	{
		return m_board[line][column];
	}
	else
	{
		throw "Index out of range";
	}
}
const std::optional<Piece>& Board::operator[](const Position& position) const
{
	const auto& [line, column] = position;
	if (line < m_board.size() && column < m_board.at(line).size())
	{
		return m_board[line][column];
	}
	else
	{
		throw "Index out of range";
	}
}
bool Board::FullBoard()
{
	for (int row = 0; row < SIZE; ++row) {

		if (std::find(m_board[row].begin(), m_board[row].end(), std::nullopt) != m_board[row].end()) {
			return false;
		}
	}
	return true;
}
Board::Neighbor Board::GetNeighbor(int row, int column, const Shape& shape) const
{
	Position position;
	Piece::Color color;

	try {
		if (m_board.at(row).at(column).has_value())
		{
			position.first = row;
			position.second = column;
			color = m_board.at(row).at(column).value().GetColor();
			return std::make_pair(position, color);
		}
		else {
			position.first = -1;
			position.second = -1;
			color = Piece::Color::NONE;
			return std::make_pair(position, color);
		}
	}
	catch (std::out_of_range const& exc) {
		return std::nullopt;

	}
}
Board::Neighbor Board::GetNeighborLeft(int row, int column, const Shape& shape) const
{
	column--;
	return GetNeighbor(row, column, shape);
}

Board::Neighbor Board::GetNeighborRight(int row, int column, const Shape& shape) const
{
	column++;
	return GetNeighbor(row, column, shape);
}

Board::Neighbor Board::GetNeighborTopLeft(int row, int column, const Shape& shape) const
{
	switch (shape)
	{
	case Shape::HEXAGON:
		if (row < SIZE) {
			row--;
			column--;
		}
		else {
			row--;
		}
		break;
	case Shape::PARALLELOGRAM:
		row--;
		break;
	case Shape::TRIANGLE:
		row--;
		column--;
		break;
	default:
		break;
	}

	return GetNeighbor(row, column, shape);
}

Board::Neighbor Board::GetNeighborTopRight(int row, int column, const Shape& shape) const
{
	switch (shape)
	{
	case Shape::HEXAGON:
		if (row < SIZE) {
			row -= 1;
		}
		else {
			row -= 1;
			column += 1;
		}
		break;
	case Shape::PARALLELOGRAM:
		row -= 1;
		column += 1;
		break;
	case Shape::TRIANGLE:
		row -= 1;
		break;
	default:
		break;
	}

	return GetNeighbor(row, column, shape);
}
Board::Neighbor Board::GetNeighborBottomLeft(int row, int column, const Shape& shape) const
{
	switch (shape)
	{
	case Shape::HEXAGON:
		if (row < SIZE - 1) {
			row += 1;
		}
		else {
			row += 1;
			column -= 1;
		}
		break;
	case Shape::PARALLELOGRAM:
		row += 1;
		column -= 1;
		break;
	case Shape::TRIANGLE:
		row += 1;
		break;
	default:
		break;
	}

	return GetNeighbor(row, column, shape);
}

Board::Neighbor Board::GetNeighborBottomRight(int row, int column, const Shape& shape) const
{
	switch (shape)
	{
	case Shape::HEXAGON:
		if (row < SIZE - 1) {
			row += 1;
			column += 1;
		}
		else {
			row += 1;
		}
		break;
	case Shape::PARALLELOGRAM:
		row += 1;
		break;
	case Shape::TRIANGLE:
		row += 1;
		column += 1;
		break;
	default:
		break;
	}

	return GetNeighbor(row, column, shape);
}

bool Board::BFS(const Board& board, Position start, Position end, Piece::Color color)
{
	std::set<Board::Position> visited;
	std::queue<Board::Position> path;
	path.push(start);

		auto pushToPath = [&color, &visited, &path](std::pair<Position, Piece::Color> neighbor) {

			const auto& [position, pieceColor] = neighbor;
			if (pieceColor == color && visited.find(position) == visited.end()) path.push(position);
		};

		while (!path.empty()) {
	
			Board::Position current = path.front();
			const auto& [line, column] = current;
			path.pop();
	
			if (current == end) {
				return true;
			}
			else if (visited.find(current) == visited.end()) {
	
				visited.insert(current);

				if (board.GetNeighborTopLeft(line, column, board.m_shape).has_value()) {
					pushToPath(board.GetNeighborTopLeft(line, column, board.m_shape).value());
				}

				if (board.GetNeighborTopRight(line, column, board.m_shape).has_value()) {
					pushToPath(board.GetNeighborTopRight(line, column, board.m_shape).value());
				}

				if (board.GetNeighborLeft(line, column, board.m_shape).has_value()) {
					pushToPath(board.GetNeighborLeft(line, column, board.m_shape).value());
				}

				if (board.GetNeighborRight(line, column, board.m_shape).has_value()) {
					pushToPath(board.GetNeighborRight(line, column, board.m_shape).value());
				}

				if (board.GetNeighborBottomLeft(line, column, board.m_shape).has_value()) {
					pushToPath(board.GetNeighborBottomLeft(line, column, board.m_shape).value());
				}

				if (board.GetNeighborBottomRight(line, column, board.m_shape).has_value()) {
					pushToPath(board.GetNeighborBottomRight(line, column, board.m_shape).value());
				}
	

			}
		}
		return false;
}

size_t Board::GetBoardSize() const
{
	return SIZE;
}

Board::Shape Board::GetBoardShape() const
{
	return m_shape;
}
