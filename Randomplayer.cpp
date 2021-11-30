
#include "Board.h"
#include <random>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <ctime>

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
