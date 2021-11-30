#include "string"
#include "iostream"
#include <list>
#include <random>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <ctime>

//#include "char"

//REMOVE THESE
enum class Piece { LIGHT, DARK, EMPTY, BORDER };
//main
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



//MOVE.CPP
typedef int Move;
typedef const Move NullMove;




//BOARD.H
//enum class Piece { LIGHT, DARK, EMPTY, BORDER };
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
			}
			else if (i == 44 || i == 55) {
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
			std::cout << "0" << i << "-" << squares[i];
		}
		else {
			std::cout << i << "-" << squares[i];
		}

		if (i == 9 || i == 19 || i == 29 || i == 39 || i == 49 || i == 59 || i == 69 || i == 79 || i == 89) {
			std::cout << std::endl;
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
		}
		else if (squares[i] == Piece::DARK) {
			countD += 1;
		}
	}
	if (countL > countD) {
		return Piece::LIGHT;
	}
	else if (countL < countD) {
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
	//possibleMoves = NULL;
	if (possibleMoves.empty()) {
		Piece winnersPiece = getWinner();
		std::cout << winnersPiece << " is the winner.";
	}

	else {
		std::cout << "The number of moves that are currently available are: " << std::endl;
	}
}

int Board::numMoves() const {
	return possibleMoves.size();
}

Move Board::getMove(int, int) const {
	Move m1 = 3;
	return m1;
}
//BOARD.CPP ENDS HERE




//PLAYER.H
class Player {
public:
	std::string  name;
	Piece playerPiece;



	Player(const std::string& nameIn, Piece pieceIn);

	Piece getPiece() const;

	virtual void makeMove(Board& boardIn) = 0;

};










//PLAYER.CPP
Player::Player(const std::string& nameIn, Piece pieceIn) {
	this->name = nameIn;
	this->playerPiece = pieceIn;
}

Piece Player::getPiece()const {
	return this->playerPiece;
}









//HUMANPLAYER.H
class HumanPlayer :public Player {
	HumanPlayer();
	void makeMove(Board& boardIn);
};





//HUMANPLAYER.CPP
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



//COMPUTERPLAYER.H
class ComputerPlayer :public Player {
public:

	ComputerPlayer(Piece computerPiece);
	void makeMove(Board& boardIn);
};





//COMPUTERPLAYER.CPP
ComputerPlayer::ComputerPlayer(Piece computerPiece) :Player("name", Piece::EMPTY) {

	//	 Player cp1 = ("Name", Piece::EMPTY);

	static char nameVariation;
	std::string computerName = "Computer " + nameVariation;
	Player::name = computerName;
	Player::playerPiece = computerPiece;
}

void ComputerPlayer::makeMove(Board& boardIn) {

}







class RandomPlayer : public ComputerPlayer {

	void makeMove(Board& boardIn);

};


void RandomPlayer::makeMove(Board& boardIn) {
	Move playerMove;
	std::cout << "Where do you want to your piece: ";
	std::cin >> playerMove;
	std::cout << std::endl;

	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution(0, 64);

	std::cout << distribution(device) << std::endl;


	boardIn.makeMove(getPiece(), playerMove);
}








//GAME.h
class Game {

	Board gameBoard;
	HumanPlayer* player1;
	ComputerPlayer* player2;

public:
	Game();
	~Game();
	void selectPlayers();
	Player* nextPlayer() const;
	bool isRunning() const;
	void play();
	void announceWinner();

};


//GAME.CPP
Game::Game() {
	gameBoard;
	player1 = NULL;
	player2 = NULL;
}

Game::~Game() {
	delete player1;
	delete player2;
}

void Game::selectPlayers() {
	std::string firstPlayer;
	std::string secondPlayer;
	std::string playerName;

	std::cout << "Please enter the type of the first player(human/computer): ";
	std::cin >> firstPlayer;

	if (firstPlayer == "human") {
		std::cout << "Please enter the name of the player: ";
		std::cin >> playerName;
	}
	else if (firstPlayer == "computer")
	{
		//firstPlayer = computer;
	}

	std::cout << "Please enter the second player(human/computer):";
	std::cin >> secondPlayer;

	if (secondPlayer == "human") {
		std::cout << "Please enter the name of the player: ";
		std::cin >> playerName;
	}
	else if (secondPlayer == "computer")
	{
		//secondPlayer = computer;
	}

	//Loop for invalid answers

   // player1 = new HumanPlayer;

}

Player* Game::nextPlayer() const {
	return player1;
}

bool Game::isRunning() const {
	return true;
}

void Game::play() {

}

void Game::announceWinner() {

}























//MAIN
int main() {

	Move NullMove = 200;


	Board myBoard;
	myBoard.display();




	/*const Move Nullmove = 100;


	ComputerPlayer cp1(Piece::LIGHT);


	Board b1;
	b1.display();*/



}

//std::ostream& operator<< (std::ostream& stream, const Piece& pieceIn)
//{
//	if (pieceIn == Piece::LIGHT) {
//		stream << "LIGHT";
//	}
//
//	if (pieceIn == Piece::DARK) {
//		stream << "DARK";
//	}
//
//	if (pieceIn == Piece::EMPTY) {
//		stream << "EMPTY";
//	}
//
//	if (pieceIn == Piece::BORDER) {
//		stream << "BOARDER";
//	}
//	return stream;
//}




//something
