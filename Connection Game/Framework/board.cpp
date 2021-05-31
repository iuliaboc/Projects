#include "board.h"

Board::Board(size_t constant, const Shape& shape)
    :SIZE(constant), m_shape(shape)
{
    switch (shape)
    {
    case Shape::HEXAGON:
        m_board.resize(SIZE * 2 - 1);
        int nrRows;
        for (int index = 0; index < SIZE * 2 - 1; ++index) {
            if (index < SIZE)
            {
                nrRows = SIZE + index;
                m_board.at(index).resize(nrRows);
            }
            else {
                m_board.at(index).resize(--nrRows);
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

size_t Board::GetSize() const noexcept
{
    return SIZE;
}

const char emptyBoardCell[] = "*";
std::ostream& operator<<(std::ostream& out, const Board& board)
{
    std::string spacing = "";
    out << '\n';

    if (board.m_shape == Board::Shape::PARALLELOGRAM) {
        out.width(5);
        for (int i = 0; i < board.SIZE; ++i) {
            out << "R ";
        }
        out << '\n';
        out << '\n';
    }

    for (int indexRow = 0; indexRow < board.m_board.size(); ++indexRow) {
        switch (board.m_shape)
        {
        case Board::Shape::HEXAGON:
            spacing.resize(board.m_board.at(board.m_board.size() / 2).size() - board.m_board.at(indexRow).size(), ' ');
            break;
        case Board::Shape::PARALLELOGRAM:
            spacing += ' ';
            break;
        case Board::Shape::TRIANGLE:
            spacing.resize(board.m_board.size() - board.m_board.at(indexRow).size(), ' ');
            break;
        }

        out << spacing;

        if (board.m_shape == Board::Shape::PARALLELOGRAM) {
            out << "B  ";
        }
        for (int indexColumn = 0; indexColumn < board.m_board.at(indexRow).size(); ++indexColumn) {

            if (auto& optPiece = board[{indexRow, indexColumn}]; optPiece) {
                out << optPiece.value() << " ";
            }
            else {
                out << emptyBoardCell << " ";
            }

            if (indexColumn == board.m_board.at(indexRow).size() - 1 && (board.m_shape == Board::Shape::PARALLELOGRAM)) {
                out << "  B";
            }

        }

        out << '\n';


    }

    if (board.m_shape == Board::Shape::PARALLELOGRAM) {
        out << '\n';
        out.width(17);
        for (int i = 0; i < board.SIZE; ++i) {
            out << "R ";
        }
        out << '\n';
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
Board::Neighbor Board::GetNeighborLeft(int row, int column, const Shape& shape) const
{
    Position position;
    Piece::Color color;
    column -= 1;

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

Board::Neighbor Board::GetNeighborRight(int row, int column, const Shape& shape) const
{
    Position position;
    Piece::Color color;
    column += 1;

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



Board::Neighbor Board::GetNeighborTopLeft(int row, int column, const Shape& shape) const
{
    Position position;
    Piece::Color color;
    switch (shape)
    {
    case Shape::HEXAGON:
        if (row < SIZE) {
            row -= 1;
            column -= 1;
        }
        else {
            row -= 1;
        }
        break;
    case Shape::PARALLELOGRAM:
        row -= 1;
        break;
    case Shape::TRIANGLE:
        row -= 1;
        column -= 1;
        break;
    default:
        break;
    }

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

Board::Neighbor Board::GetNeighborTopRight(int row, int column, const Shape& shape) const
{
    Position position;
    Piece::Color color;
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
Board::Neighbor Board::GetNeighborBottomLeft(int row, int column, const Shape& shape) const
{
    Position position;
    Piece::Color color;
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

Board::Neighbor Board::GetNeighborBottomRight(int row, int column, const Shape& shape) const
{
    Position position;
    Piece::Color color;
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

bool Board::BFS(const Board& board, Position start, Position end, Piece::Color color)
{
    std::set<Board::Position> visited;
        std::queue<Board::Position> path;
        path.push(start);
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

                    const auto& [position, pieceColor] = board.GetNeighborTopLeft(line, column, board.m_shape).value();

                    if (pieceColor == color && visited.find(position) == visited.end())
                    {
                        path.push(position);
                    }
                }

                if (board.GetNeighborTopRight(line, column, board.m_shape).has_value()) {

                    const auto& [position, pieceColor] = board.GetNeighborTopRight(line, column, board.m_shape).value();

                    if (pieceColor == color && visited.find(position) == visited.end())
                    {
                        path.push(position);
                    }
                }

                if (board.GetNeighborLeft(line, column, board.m_shape).has_value()) {

                    const auto& [position, pieceColor] = board.GetNeighborLeft(line, column, board.m_shape).value();

                    if (pieceColor == color && visited.find(position) == visited.end())
                    {
                        path.push(position);
                    }

                }
                if (board.GetNeighborRight(line, column, board.m_shape).has_value()) {

                    const auto& [position, pieceColor] = board.GetNeighborRight(line, column, board.m_shape).value();

                    if (pieceColor == color && visited.find(position) == visited.end())
                    {
                        path.push(position);
                    }
                }
                if (board.GetNeighborBottomLeft(line, column, board.m_shape).has_value()) {

                    const auto& [position, pieceColor] = board.GetNeighborBottomLeft(line, column, board.m_shape).value();

                    if (pieceColor == color && visited.find(position) == visited.end())
                    {
                        path.push(position);
                    }
                }
                if (board.GetNeighborBottomRight(line, column, board.m_shape).has_value()) {

                    const auto& [position, pieceColor] = board.GetNeighborBottomRight(line, column, board.m_shape).value();

                    if (pieceColor == color && visited.find(position) == visited.end())
                    {
                        path.push(position);
                    }


                }
            }
        }
        return false;
}

std::vector<std::vector<std::optional<Piece>>> Board::GetBoard()
{
    return m_board;
}

void Board::ClearBoard()
{
    for(int line=0;line<m_board.size();++line)
    {
        for(int column=0;column<m_board.at(line).size();++column)
        {
            Piece piece(Piece::Color::NONE);
            m_board.at(line).at(column)=std::move(piece);
        }
    }
}
