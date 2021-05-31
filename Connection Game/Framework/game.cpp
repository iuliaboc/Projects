#include "game.h"

Game::Game()
{

}

Game::Game(const std::string &name)
    : m_name{ name }
{
}

void Game::Run()
{
    YGame y;

    std::string gameName;
    gameName=MainWindow::game;

    y.Run();
}

bool Game::Finish(bool finish)
{
    if(finish)
    {
        return true;
    }
    return false;
}


