//PLAYER.CPP
#include "Player.h"

Player::Player(const std::string& nameIn, Piece pieceIn) {
	this->name = nameIn;
	this->playerPiece = pieceIn;
}

Piece Player::getPiece()const {
	return this->playerPiece;
}
