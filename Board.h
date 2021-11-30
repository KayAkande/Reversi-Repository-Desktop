#include "iostream"
#include "list"
#include "Move.cpp"

//BOARD.H
//typedef int Move;
enum class Piece { LIGHT, DARK, EMPTY, BORDER };
const int boardSqaures = 100;
class Board {

	Piece squares[boardSqaures];
	std::list <Move> possibleMoves;

public:

	Board();

	void reset();

	void display();

	void makeMove(Piece pieceIn, Move moveIn);

	bool isLegal(Piece pieceIn, Move moveIn);

	Piece getWinner() const;

	Piece getPlayer() const;

	Piece getPiece();

	void genMoves();

	int numMoves() const;

	Move getMove(int, int) const;

};
