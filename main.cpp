//MAIN


#include "Board.h"
#include "Computerplayer.h"
#include "Move.cpp"

int main() {

	Move NullMove = 200;


	Board myBoard;
	myBoard.display();




	const Move Nullmove = 100;


	ComputerPlayer cp1(Piece::LIGHT);


	Board b1;
	b1.display();



}

std::ostream& operator<< (std::ostream& stream, const Piece& pieceIn)
{
	if (pieceIn == Piece::LIGHT) {
		stream << "LIGHT";
	}

	if (pieceIn == Piece::DARK) {
		stream << "DARK";
	}

	if (pieceIn == Piece::EMPTY) {
		stream << "EMPTY";
	}

	if (pieceIn == Piece::BORDER) {
		stream << "BOARDER";
	}
	return stream;
}
