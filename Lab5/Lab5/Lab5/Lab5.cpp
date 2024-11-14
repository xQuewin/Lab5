
/*
Cole Fortune
C++ Coding Fall 2024
Due: 11/12/2024
Lab 5 Number Guessing Game
Description: Write a number-guessing game in which the computer selects a random
number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At
the end of each game, users should be told whether they won or lost, and then be asked
whether they want to play again. When the user quits, the program should output the
total number of wins and losses. To make the game more interesting, the program
should vary the wording of the messages that it outputs for winning, for losing, and for
asking for another game. Create 10 different messages for each of these cases, and use
random numbers to choose among them. This application should use at least one Do-
While loop and at least one Switch statement. Write your C++ code using good style and
documenting comments. You should use classes in your code as well. Your source code
file should be called Lab5.cpp.
*/







#include <iostream>
#include "Game.h"

int main() {

	Game game;
	int choice = 0;
	using namespace std;

	cout << "You are now playing the Random Number guessing game" <<"\nPlease select one of the options below" << endl;

	// Main menu siwtch statement
	while (true)
	{
		
		cout << "1. Play Game" << endl; //start the game
		cout << "2. Scoreboard" << endl; //display all time scores
		cout << "3. Quit" << endl; //end game and display all time scores
		cout << "4. Reset Scores" << endl; //added reset scores option

		cout << "Please enter your choice: ";
		cin >> choice;
		if (cin.fail()) //checks if the input is valid
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid imput try a different input" << endl;
			continue;
		}

		game.endScore();
		switch (choice) //switch statement for the main menu
		{
		case 1:
			//starts the game
			cout << "You have chosen to play the game!" << endl;
			game.start();
			break;
		case 2:
			//tells you all time scores
			cout << "You have chosen to see the end scores" << endl;
			game.displayScore();
			break;
		case 3:
			//quits the game and displays all time scores
			cout << "You have chosen to exit the game" << endl;
			cout << "Your final results were:" << endl;
			game.displayScore();
			return 0;
		case 4:
			//resets the scores
			cout << "You have chosen to clear any score history" << endl;
			game.reset();
			break;
		default:
			cout << "Invalid imput try a different input" << endl;
			break;
		}
	}

	return 0;

}