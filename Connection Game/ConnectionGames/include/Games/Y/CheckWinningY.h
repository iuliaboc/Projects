#pragma once
#include"../../Framework/Player.h"
#include"YBoard.h"

inline bool CheckWinningY(std::reference_wrapper<Player>& placingPlayer, const std::unique_ptr<Board>& board)
{
	YBoard* yBoardPointer = static_cast<YBoard*>(board.get());
	if (yBoardPointer->BFS_AllEdges(*yBoardPointer, placingPlayer.get().GetColor()) ||
		yBoardPointer->BFS_CornerToOpositEdge(*yBoardPointer, placingPlayer.get().GetColor()))
		return true;

	return false;
}