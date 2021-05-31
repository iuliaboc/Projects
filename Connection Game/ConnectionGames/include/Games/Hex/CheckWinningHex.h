#pragma once
#include"../../Framework/Player.h"
#include"HexBoard.h"

inline bool CheckWinningHex(std::reference_wrapper<Player>& placingPlayer, const std::unique_ptr<Board>& board) {
	
	HexBoard* hexBoardPointer = static_cast<HexBoard*>(board.get());
	if (hexBoardPointer->BFS_Bridge(*hexBoardPointer, placingPlayer.get().GetColor())) 
		return true;

	return false;
}