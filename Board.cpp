#include "Board.h"
#include "iostream"


std::ostream& operator<< (std::ostream& stream, const Piece& pieceIn)
{
	if (pieceIn == Piece::LIGHT) {
		stream << " LIGHT  ";
	}

	if (pieceIn == Piece::DARK) {
		stream << "  DARK  ";
	}

	if (pieceIn == Piece::EMPTY) {
		stream << " EMPTY  ";
	}

	if (pieceIn == Piece::BORDER) {
		stream << "BOARDER ";
	}
	return stream;
}


//BOARD.CPP
Board::Board() {
	reset();
}

void Board::reset() {
	int val = 9;
	for (int i = 0; i < boardSqaures; i++) {
		bool something = false;
		if (i < 10 || i > 88) {
			squares[i] = Piece::BORDER;
		}

		else if (i % 10 == 0) {
			squares[i] = Piece::BORDER;
			something = true;
		}

		else if (i == val) {
			squares[i] = Piece::BORDER;
		}

		else {
			if (i == 45 || i == 54) {
				squares[i] = Piece::DARK;
			}else if (i == 44 || i == 55) {
				squares[i] = Piece::LIGHT;
			}
			else {
				squares[i] = Piece::EMPTY;
			}
		}


		if (something == true) {
			squares[i - 1] = Piece::BORDER;
		}

	}

}

void Board::display() {
	for (int i = 0; i < boardSqaures; i++) {
		if (i < 10) {
			std::cout << "0"<< i << "-" << squares[i];
		}else{
			std::cout << i << "-" << squares[i];
		}

		if (i == 9 || i == 19 || i == 29 || i == 39 || i == 49 || i == 59 || i == 69 || i == 79 || i == 89) {
			std::cout <<std::endl;
		}

	}

}

void Board::makeMove(Piece pieceIn, Move moveIn) {
	genMoves();

}

bool Board::isLegal(Piece pieceIn, Move moveIn) {
	for (auto i : possibleMoves) {
		if (i == moveIn) {
			return true;
		}

	}
	return false;

}

Piece Board::getWinner() const {
	int countD = 0;
	int countL = 0;
	for (int i = 0; i < boardSqaures; ++i) {
		if (squares[i] == Piece::LIGHT) {
			countL += 1;
		}else if (squares[i] == Piece::DARK) {
			countD += 1;
		}
	}
	if (countL > countD) {
		return Piece::LIGHT;
	}else if (countL < countD) {
		return Piece::DARK;
	}
	else if (countL == countD) {
		return Piece::BORDER;
	}
  
}

Piece Board::getPlayer() const {
	return Piece::BORDER;
}

Piece Board::getPiece() {
	return Piece::BORDER;
}

void Board::genMoves() {
	//	possibleMoves = NULL;
	if (possibleMoves.empty()) {
		Piece win = getWinner();
		std::cout << win << " is the winner.";
	}
	std::cout << "The number of moves that are currently available are: " << std::endl;

}

int Board::numMoves() const {
	return possibleMoves.size();
}

Move Board::getMove(int, int) const {
	Move m1 = 3;
	return m1;
}
//BOARD.CPP ENDS HERE
