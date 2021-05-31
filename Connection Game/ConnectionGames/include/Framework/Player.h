#pragma once
#include"../Framework/Board.h"
#include"../Framework/Piece.h"
#include<fstream>
#include <iostream>
#include <exception>

class Player
{
public:
	Player() = default;
	Player(const std::string& name, Piece::Color color);
	friend std::ostream& operator<<(std::ostream& out, const Player& player);
	Board::Position PlacePiece(std::istream& in, Board& board);

	void SwapColor(Player& other);
	void SetColor(Piece::Color color);
	Piece::Color GetColor() const noexcept;
	std::string GetName() const noexcept;
	void SetName(const std::string& name);

private:
	std::string m_name;
	Piece::Color m_color;
};

