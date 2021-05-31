#include "../../include/Framework/Piece.h"

Piece::Piece()
	:Piece(Color::NONE)
{
}

Piece::Piece(Color color)
	:m_color{color}
{
}

Piece::Piece(const Piece& piece)
{
	*this = piece;
}

Piece::Piece(Piece&& piece) noexcept
{
	*this = std::move(piece);
}

Piece& Piece::operator=(const Piece& piece)
{
	if (this != &piece)
	{
		m_color = piece.m_color;
	}
	return *this;
}

Piece& Piece::operator=(Piece&& piece) noexcept
{
	if (this != &piece)
	{
		m_color = piece.m_color;
		new(&piece) Piece();
		//*this = std::exchange(piece, Piece());
	}
	return *this;
}

Piece::Color Piece::GetColor() const 
{
	return m_color;
}

std::string Piece::GetColorString(const Color& color)
{
	switch (color)
	{
	case Piece::Color::RED:
		return "R";
	case Piece::Color::BLUE:
		return "B";
	default:
		return "*";
	}
}

std::ostream& operator<<(std::ostream& out, const Piece& piece)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, static_cast<int>(piece.m_color));
	return out << Piece::GetColorString(piece.m_color);
	
}
