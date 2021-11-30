//HUMANPLAYER.CPP

#include "Humanplayer.h"

void HumanPlayer::makeMove(Board& boardIn) {

	/*HumanPlayer::HumanPlayer() :Player("name", Piece::EMPTY) {

	}*/

	//	ComputerPlayer::ComputerPlayer(Piece computerPiece) : Player;

	int playerMove;
	std::cout << "Where do you want to your piece: ";
	std::cin >> playerMove;
	std::cout << std::endl;

	boardIn.makeMove(getPiece(), playerMove);
}
