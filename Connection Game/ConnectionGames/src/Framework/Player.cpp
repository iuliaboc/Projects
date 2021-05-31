#include "../../include/Framework/Player.h"

std::ostream& operator<<(std::ostream& out, const Player& player)
{
	return out << player.m_name;
}

Player::Player(const std::string& name, Piece::Color color) :m_name(name), m_color(color)
{

}
void Player::SetColor(Piece::Color color)
{
	this->m_color = color;
}

void Player::SwapColor(Player& other)
{
	auto aux = this->m_color;
	this->SetColor(other.GetColor());
	other.SetColor(aux);
}


Board::Position Player::PlacePiece(std::istream& in, Board& board)
{
	uint16_t line;
	uint16_t column;
	Piece piece(m_color);

	if (in >> line) {
		if (in >> column) {

			Board::Position position = { static_cast<uint8_t>(line), static_cast<uint8_t>(column) };

			auto& optionalPiece = board[position];

			if (optionalPiece)
				throw "That position is occupied by another piece.";

			optionalPiece = std::move(piece);

			return position;


		}
	}


	in.clear();
	in.seekg(std::ios::end);

	throw "Please enter other numbers.";
	
}

Piece::Color Player::GetColor() const noexcept
{
	return m_color;
}


std::string Player::GetName() const noexcept
{
	return m_name;
}

void Player::SetName(const std::string& name) 
{
	m_name = name;
}

