#include <iostream>
#ifndef Game_H
#define Game_H
using namespace std;
class Game {
public:
	Game();
	~Game();
	void start();
	void getScores();
	void endScore();
	void displayScore();
	void getConditionalMessage();
	void getMessage();
	void reset();

private:
	bool begin = true;
	int guess = 0;
	int randomNumber = 0;
	int maxG = 20;
	int aGuesses = 0;
	string newgame = " ";
	float totalWins = 0;
	float totalLosses = 0;
	
};







#endif // !Game_H
