//GAME.h


#include "Board.h"
#include "Player.h"
#include "Humanplayer.h"


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
