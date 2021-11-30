//GAME.CPP

#include "Game.h"
#include "iostream"

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
