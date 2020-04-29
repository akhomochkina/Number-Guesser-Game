#include <iostream>
using namespace std;

int main()
{
	/*

	Pseudo code:

	do
	{
		Play the game

	} while (want to play again)

	Play the game:

	1. set the secret number - set it to known value for now
	2. set the number of guesses -> ceil(log2(100)) if range 1-100

	do {
	
	3. promt the player to make a guess + output number of guesses left
	4. get the guess from the player
	5. check if the guess is correct (equal to secret number)
		5a. If guess is not correct (not equal to secret number) then 
			+ decrement number of guesses left
			+ check if the guess was higher or lower than the secret number
				- if higher -> print the guess is too high
				- else if guess was lower -> print the guess is too low

	} while (the game not over)

	Display result of the game - tell the player if they won or lost.

	Functions:

	Play the game -> PlayGame();
	Want to play again -> PlayAgain();
	Get the guess from player -> GetGuess();
	Game over -> IsGameOver();
		(number of guesses left == 0 || guess == secret number);
	Display results -> DisplayResult();
		(if player guessed the number -> print they won and print the secret number);
		(else print they lost and print the secret number);

	*/


	return 0;
}
