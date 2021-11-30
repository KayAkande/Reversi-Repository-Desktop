//COMPUTERPLAYER.H

#include "Board.h"


#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

class ComputerPlayer :public Player {
public:

	ComputerPlayer(Piece computerPiece);
	void makeMove(Board& boardIn);
};


#endif
