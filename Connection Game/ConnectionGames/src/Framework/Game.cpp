#include "../../include/Framework/Game.h"

void Game::SetGameName(Game::Name name)
{
	m_name = name;
}

void Game::SetBoardType()
{
	switch (m_name)
	{
	case Name::HEX:
		m_board = std::unique_ptr<Board>(new HexBoard());
		break;
	case Name::Y:
		m_board = std::unique_ptr<Board>(new YBoard());
		break;
	case Name::HAVANNAH:
		m_board = std::unique_ptr<Board>(new HavannahBoard());
		break;
	default:
		break;
	}
	return;
}
void Game::InitialPhase()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	std::string name;
	std::cout << "Player1 name: ";
	SetConsoleTextAttribute(hConsole, 4);
	std::cin >> name;
	m_player1.SetName(name);
	m_player1.SetColor(Piece::Color::RED);
	
	SetConsoleTextAttribute(hConsole, 7);

	std::cout << "Player2 name: ";
	SetConsoleTextAttribute(hConsole, 1);
	std::cin >> name;
	m_player2.SetName(name);
	m_player2.SetColor(Piece::Color::BLUE);

	SetConsoleTextAttribute(hConsole, 7);
}


void printToCentre(const std::string& s)
{
	const int linelength = 100;
	int spaces = 0;
	spaces = (linelength - s.size()) / 2;
	if (spaces > 0) std::cout << std::string(spaces, ' ');
	std::cout << s << '\n';
}

void Game::PickGame()
{
	int choice;

	printToCentre("1. Play Hex");
	printToCentre("2. Play Y");
	printToCentre("3. Play Havannah");
	printToCentre("4. Exit");
	printToCentre("Your choice:");

	std::cin >> choice;
	switch (choice)
	{
	case 1: 
	{
		SetGameName(Game::Name::HEX);
		break;
	}
	case 2: 
	{
		SetGameName(Game::Name::Y);
		break;
	}
	case 3: 
	{
		SetGameName(Game::Name::HAVANNAH);
		break;
	}
	case 4:
	{
		SetGameName(Game::Name::EXIT);
		break;
	}
	default:
		break;
	}
}

void Game::PieRule(std::reference_wrapper<Player>& placingPlayer, std::reference_wrapper<Player>& waitingPlayer)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char swapChoice;
	SetConsoleTextAttribute(hConsole, static_cast<int>(placingPlayer.get().GetColor()));
	std::cout << placingPlayer.get().GetName();
	SetConsoleTextAttribute(hConsole, 7);
	std::cout << ", would you like to switch color? (y/n) \n";
	std::cin >> swapChoice;
	if (swapChoice == 'y') {
		placingPlayer.get().SwapColor(waitingPlayer);
		std::swap(placingPlayer, waitingPlayer);
	}
	return;
}

bool Game::CheckWinning(std::reference_wrapper<Player>& placingPlayer, Board::Position& lastPlaced)
{
	switch (m_name)
	{
	case Game::Name::HEX:
		if (CheckWinningHex(placingPlayer, m_board)) {
			return true;
		}
		break;
	case Game::Name::Y: {
		if (CheckWinningY(placingPlayer, m_board)) {
			return true;
		}
		break;
	}
	case Game::Name::HAVANNAH: {
		if (ChecksWinningHavannah(placingPlayer, m_board, lastPlaced)) {
			return true;
		}
		break;
	}
	default: break;
	}
	return false;
}


void Game::Play()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetBoardType();

	auto placingPlayer = std::ref(m_player1);
	auto waitingPlayer = std::ref(m_player2);

	bool firstRound = true;

	while (true) {

		system("cls");
		std::cout << "The board looks like this:\n" << std::endl;
		std::cout << *m_board << std::endl;

		SetConsoleTextAttribute(hConsole, static_cast<int>(placingPlayer.get().GetColor()));
		std::cout << placingPlayer;
		SetConsoleTextAttribute(hConsole, 7);
		std::cout<< " please place the piece : ";
		Board::Position piecePosition;
		while (true) {
			try {
				piecePosition = placingPlayer.get().PlacePiece(std::cin, *m_board);
				break;
			}
			catch (const char* message) {
				std::cout << message << std::endl;
			}
		}


		if (CheckWinning(placingPlayer, piecePosition)) {
			system("cls");
			std::cout << "The final board looks like this:\n" << std::endl;
			std::cout << *m_board << std::endl;
			std::cout << "END GAME! ";
			SetConsoleTextAttribute(hConsole, static_cast<int>(placingPlayer.get().GetColor())); 
			std::cout << placingPlayer.get().GetName();
			SetConsoleTextAttribute(hConsole, 7);
			std::cout << " WON!\n \n";
			break;
		}

		if (m_board.get()->FullBoard()) {
			std::cout << "It's a draw!\n";
			break;
		}

		std::swap(placingPlayer, waitingPlayer);

		if (firstRound) {
			std::cout << *m_board << std::endl;
			firstRound = false;
			Game::PieRule(placingPlayer, waitingPlayer);
		}

	}
}

void Game::Rematch()
{
	int choice;

	printToCentre("1. Rematch");
	printToCentre("2. Play another");
	printToCentre("3. Exit");
	printToCentre("Your choice:");

	std::cin >> choice;
	switch (choice)
	{
	case 2:
		SetGameName(Game::Name::NEW);
		break;
	case 3:
		SetGameName(Game::Name::EXIT);
		break;
	default: break;
	}
}

void Game::Run()
{
	InitialPhase();
	while (m_name != Game::Name::EXIT) {
		PickGame();
		while (m_name != Game::Name::NEW && m_name != Game::Name::EXIT)
		{
			Play();
			Rematch();
		}
	}
}
