#ifndef GAME_H
#define GAME_H

#pragma once
#include<iostream>
#include<string>
#include"hexgame.h"
#include"piece.h"
#include"yframe.h"
#include"board.h"
#include"havannahgame.h"
#include"player.h"
#include<QMouseEvent>

#include"mainwindow.h"
#include"yWindow.h"

class Game:public MainWindow, public YWindow, public YFrame
{
public:
    Game();
    Game(const std::string& name);

    void Run();
    bool Finish(bool finish);

private:
    std::string m_name;
};

#endif // GAME_H
