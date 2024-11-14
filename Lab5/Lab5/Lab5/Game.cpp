#include "Game.h"
#include <iostream>
#include <fstream>

using namespace std;

Game::Game()
{
	//initialize variables
	guess = 0;
	randomNumber = 0;
	aGuesses = 0;
	newgame = ' ';
	totalWins = 0;
	totalLosses = 0;

}

Game::~Game()
{
}

void Game::start()
{
	//play the game
	if (begin == true)
	{
		//do while loop to play the game
		do
		{
			//gets a random number between 0 and 100
			srand(time(0));
			randomNumber = rand() % 100 + 1;
			aGuesses = 0;
			cout << "Guess the number from 1 to 100, you have 20 chances" << endl;
			cout << "Enter your guess >_<: ";

			//gets the users guess and check if it's valid
			cin >> guess;
			while (guess < 0 || guess > 100)
			{
				cout << "Invalid imput try a different input" << endl;
				cout << "Please enter your guess: ";
				while (true) {
					cin >> guess;

				}

			}
			//while loop to check if the guess is correct
			while (guess != randomNumber && aGuesses < maxG - 1)
			{
				while (cin.fail()) //checks if the input is valid
				{
					cout << endl;
					cin.clear();
					cin.ignore();
					cout << "Invalid imput try a different input" << endl;
					cout << "Please enter your guess: ";
					cin >> guess;
				}
				if (guess < randomNumber)
				{
					cout << "You guessed too low" < endl;
				}
				else
				{
					cout << "You guessed too high" << endl;
				}
				aGuesses++;
				cout << "You have " << maxG - aGuesses << " guesses left!" << endl;
				cout << "Please enter your guess: ";
				cin >> guess;
				while (guess < 0 || guess > 100)
				{
					cout << "Invalid imput try a different input" << endl;
					cout << "Please enter your guess: ";
					cin >> guess;
				}
			}
			//if statement to check if the guess is correct
			if (guess == randomNumber)
			{
				getConditionalMessage();
				totalWins++;
				endScore();
			}
			//if the guess is incorrect
			else
			{
				getConditionalMessage();
				cout << "The number hidden was: " << randomNumber << endl;
				totalLosses++;
				endScore();
			}
			int i = 0;
			//while loop to check if the player wants to play again
			while (i == 0) {
				getMessage();

				cin >> newgame;
				if (newgame == "y")
				{
					cout << "You started a new game" << endl;
					i = 1;
				}
				else if (newgame == "n")
				{
					cout << "You have ended the game" << endl;
					i = 1;
				}
				else
				{
					cout << "you have not selected a valid input, please select a valid input" << endl;
				}

			}

		} while (newgame == "y");

	}
	else
	{
		cout << "You have decided to continue the game" << "\nGoodluck!" << endl;
		
	}
}


//gets the all time scores from a file
void Game::getScores()
{
	ifstream inputfile;
	inputfile.open("SavedData.dat");
	inputfile >> totalWins;
	inputfile >> totalLosses;
	inputfile.close();


}
//save the all time scores to a file
void Game::endScore()
{
	ofstream outputfile;
	outputfile.open("SavedData.dat");
	outputfile << totalWins << endl;
	outputfile << totalLosses << endl;
	outputfile.close();
}
//display the all time scores
void Game::displayScore()
{
	cout << "End game Wins: " << totalWins << endl;
	cout << "End game Losses: " << totalLosses << endl;

}
//gets the messages for if the player wins or loses
void Game::getConditionalMessage()
{
	srand(time(0));
	int randomMessage = rand() % 10 + 1;
	if (guess == randomNumber)
	{
		switch (randomMessage)
		{
		case 1:
			cout << "You alone are the honored one" << endl;
			break;
		case 2:
			cout << "If guessing was a profession you would be a billionaire " << endl;
			break;
		case 3:
			cout << "The world says goodmorning to the new champ" << endl;
			break;
		case 4:
			cout << "It's not about how many time you get hit, it's about how many times you get back up. You are champion!" << endl;
			break;
		case 5:
			cout << "You are the new guessing game undesputed champion of the world" << endl;
			break;
		case 6:
			cout << "On days like these we just got sit back and appreciate how smart you are " << endl;
			break;
		case 7:
			cout << "We have a new apex guessing champion" << endl;
			break;
		case 8:
			cout << "You are the John Doe of guessing" << endl;
			break;
		case 9:
			cout << "Madness, how did you guess my number" << endl;
			break;
		case 10:
			cout << "Are you cheating,are you the IRS how did you get that." << endl;
			break;

		}
	}
	else
	{

		switch (randomMessage) //switch statement for the random messages
		{
		case 1:
			cout << "Next time champ" << endl;
			break;
		case 2:
			cout << "In the end yoyu just didnt get it" << endl;
			break;
		case 3:
			cout << "You are merely delyaing the inevitable, try again" << endl;
			break;
		case 4:
			cout << "Correct! Na just playing you go it wrong" << endl;
			break;
		case 5:
			cout << "You had 1 job 20 guess how did you get it wrong" << endl;
			break;
		case 6:
			cout << "In life we have to keep on going even if we are wrong" << endl;
			break;
		case 7:
			cout << "SO we just going to keep guessing wrong?!" << endl;
			break;
		case 8:
			cout << "Nooo the guesss was wronggggg" << endl;
			break;
		case 9:
			cout << "Ares! help this person guess the right number and my soul is yours" << endl;
			break;
		case 10:
			cout << "Really man/women you know what the number is stop wasting my time!" << endl;
		}
	}
}
//gets the messages for if the player wants to play again
void Game::getMessage()
{
	cout << "I know you got another game in ya , new game (y / n)?" << endl;
	
	}



}

void Game::reset() //resets the scores
{
	totalWins = 0;
	totalLosses = 0;
	endScore();
}
