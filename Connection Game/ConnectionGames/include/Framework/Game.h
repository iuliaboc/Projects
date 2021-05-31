#pragma once
#include"../Games/Havannah/CheckWinningHavannah.h"
#include"../Games/Hex/CheckWinningHex.h"
#include"../Games/Y/CheckWinningY.h"
#include<iostream>
#include<string>

class Game
{
public:
	Game() = default;
	void Run();

	
private:
	enum class Name :uint8_t
	{
		HEX,
		HAVANNAH,
		Y, 
		NEW, 
		EXIT
	};

private:
	Name m_name;
	std::unique_ptr<Board> m_board;
	Player m_player1;
	Player m_player2;

	void SetBoardType();
	void SetGameName(Game::Name name);
	void InitialPhase();
	void PickGame();
	void PieRule(std::reference_wrapper<Player>& placingPlayer, std::reference_wrapper<Player>& waitingPlayer);
	bool CheckWinning(std::reference_wrapper<Player>& placingPlayer, Board::Position& lastPlaced);
	void Play();
	void Rematch();
};

