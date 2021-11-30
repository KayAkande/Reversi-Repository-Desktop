//PLAYER.H
#include "string"
#include "Board.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
	std::string  name;
	Piece playerPiece;



	Player(const std::string& nameIn, Piece pieceIn);

	Piece getPiece() const;

	virtual void makeMove(Board& boardIn) = 0;

};


#endif
