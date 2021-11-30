
#include "Computerplayer.h"
#include "Player.h"
#include "Board.h"



ComputerPlayer::ComputerPlayer(Piece computerPiece) : Player("name", Piece::EMPTY) {

	//	 Player cp1 = ("Name", Piece::EMPTY);

	static char nameVariation;
	std::string computerName = "Computer " + nameVariation;
//	static Player::name = computerName;
//	Player::playerPiece = computerPiece;
}

void ComputerPlayer::makeMove(Board& boardIn) {

}
