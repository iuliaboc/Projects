#pragma once
#include"../../Framework/Player.h"
#include"HavannahBoard.h"

inline bool ChecksWinningHavannah(std::reference_wrapper<Player>& placingPlayer, const std::unique_ptr<Board>& board, Board::Position& lastPlaced)
{
	HavannahBoard* havannahBoardPointer = static_cast<HavannahBoard*>(board.get());

	if (havannahBoardPointer->CheckFork(*havannahBoardPointer, placingPlayer.get().GetColor()) ||
		havannahBoardPointer->BFS_Bridge(*havannahBoardPointer, placingPlayer.get().GetColor()) ||
		havannahBoardPointer->CheckRing(lastPlaced, *havannahBoardPointer, placingPlayer.get().GetColor()))
		return true;

	return false;
}