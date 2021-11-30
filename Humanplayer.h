//HUMANPLAYER.H
#include "Board.h"
#include "Player.h"

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

class HumanPlayer :public Player {
	HumanPlayer();
	void makeMove(Board& boardIn);
};

#endif
