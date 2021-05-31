#pragma once
#include<cstdint>
#include<ostream>
#include<utility>
#include<windows.h>

class Piece
{
public:
	enum class Color :uint8_t
	{
		NONE,
		RED = 4,
		BLUE = 1
	};
public:
	Piece();
	Piece(Color color);
	Piece(const Piece& piece);
	Piece(Piece&& piece) noexcept;
	Piece& operator=(const Piece& piece);
	Piece& operator=(Piece&& piece) noexcept;
	~Piece() = default;

	Color GetColor() const;
	static std::string GetColorString(const Color& color);

	friend std::ostream& operator<<(std::ostream& out, const Piece& piece);
private:
	Color m_color;
};

