#include <iostream>
#include <cmath>
#include <cctype>
#include <stdlib.h>
#include <ctime>
#include<dos.h> 
#include <windows.h> 

using namespace std;

//function to get the guessed number from the player
int GetGuess(int numberOfTries)
{
	int guess;
	bool failure;

	do
	{
		failure = false;
		cout << "Please enter your guess (number of guesses left: " << numberOfTries << "): ";
		cin >> guess;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Input Error! Please try again!" << endl;
			failure = true;
		}

	} while (failure);

	return guess;
}

//function to determine if the game is over based on the guessed number or number of tries
bool IsGameOver(int secretNumber, int numberOfTries, int guess)
{
	return secretNumber == guess || numberOfTries <= 0;
}

//function to display results
void DisplayResult(int secretNumber, int numberOfTries)
{
	if (numberOfTries > 0)
		cout << "You got the correct number! Secret number was: " << secretNumber << endl << endl;
	else cout << "You didn't get the number! Secret number was: " << secretNumber << endl << endl;
}

//function containing logic for playing the game
void PlayGame()
{
	const int UPPER_BOUND = 100;
	int secretNumber = rand() % UPPER_BOUND;
	int numberOfTries = ceil(log2(UPPER_BOUND));
	int guess = 0;

	cout << "The range of the number is between 0 and 100" << endl << endl;

	do
	{
		guess = GetGuess(numberOfTries);

		if (guess != secretNumber)
		{
			numberOfTries--;
			if (guess > secretNumber)
				cout << "Your guess is too high!" << endl << endl;
			else cout << "Your guess is too low!" << endl << endl;
		}

	} while (!IsGameOver(secretNumber, numberOfTries, guess));

	DisplayResult(secretNumber, numberOfTries);
}

//function to determine whether or not the player want to play the game again
bool PlayAgain()
{
	char input;
	bool failure;

	do
	{
		failure = false;
		cout << endl << "Would you like to play another game? (y/n) ";
		cin >> input;


		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Input Error! Please try again..." << endl;
			failure = true;
		}
		else
		{
			//ignore characters and trasfer input to lower case
			//so that it doesn't matter if it's upper or lower
			cin.ignore(256, '\n');
			input = tolower(input);
		}

	} while (failure);

	return input == 'y';
}

int main()
{
	//create a handle - will be used to set color to the output text
	HANDLE  handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//sets the text color to green
	SetConsoleTextAttribute(handle, 2);

	cout << "Welcome to Guess The Number Game!" << endl << endl;

	//function to generate random number each time based on the internal clock
	srand((unsigned int)time(NULL));

	//starting the game
	do
	{
		PlayGame();

	} while (PlayAgain());

	cout << "Thank you for playing, GoodBye!" << endl;
	return 0;
}