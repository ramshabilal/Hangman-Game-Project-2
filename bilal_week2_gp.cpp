
/*Game Project 2
bilal_week2_gp.cpp
Ramsha Bilal
PC
*/

#include<iostream>
#include<string> 
#include<cstdlib>
#include<ctime>
#include <vector>
using namespace std;

//using global variables to access them throughout the program

string guessLetter, usedLetterBoard, usedLetters = " ", showWord[20], vocabulary[10] = { "teacher", "cat", "apple", "rose", "halloween", "warrior", "titanic", "mathematics","cake", "horse" };
int incorrectGuesses = 0, incorrectGuessReturn, flag=0, debugMode; 
const int MAX_GUESSES = 6;

/*Initialises an array by setting all indexes to "_ " and displays n number 
  of "_ " where n is the number of letters in the word to be guessed*/
void initialiseDisplay(int lengthOfWord)
{
	for (int i = 0; i < lengthOfWord; i++)
	{
		showWord[i] = "_ ";
		cout << showWord[i];
	}

	cout << endl;
}

/*displays the current state of the array showWord therefore, displays the letters 
  that are guessed by the user and hides those that are not guessed by user*/
void display(int lengthOfWord)
{
	for (int m = 0; m < lengthOfWord; m++)
		cout << showWord[m] << " ";
	cout << endl;

}

/*allows the user to take turn, is that enter a letter - if the guess is correct, it replaces a dash "_" 
  from the array showWord and places the letter in its right position. A flag value is returned to main 
  to indicate whether guess was correct or not. it also informs user if guess was incorrect.*/
int hangMan(string wordToGuess, int lengthOfWord, int flag)
{
	cout << "guess a letter!\n"; 
	cin >> guessLetter;

	for (int c = 0; c < lengthOfWord;c++)
	{
		if ((guessLetter == wordToGuess.substr(c, 1)) && (guessLetter!= showWord[c]))
		{
			showWord[c] = guessLetter;
			
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "Incorrect guess!\n" << " \n";
	return flag;
}

/*It checks if all the letters in the word to be guessed are correctly guessed by the user. if yes, it returns a value
  to main that indicates that the loop should be terminated and game should be stopped as user has won.*/
int checkString(int lengthOfWord)
{
	int totalLetters = 0;
	for (int l = 0; l <= (lengthOfWord - 1); l++)
	{
		if (showWord[l] != "_ ") 
			totalLetters++;
	}
	if (totalLetters == lengthOfWord)
		return 1;
	else
		return 0;
}

/*It displays the letters that the user has already entered after each turn*/
string displayLetterBoard()
{
	usedLetters = usedLetters + " " + guessLetter;
	return usedLetters; 
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	string wordToGuess = vocabulary[rand() % 10];      //index of vocabulary array is from 0-9
	int lengthOfWord = wordToGuess.length();
	int loopStopper = 0;

	cout << "Welcome to Hangman. Press 1 if you want to play in debug mode. Otherwise, press 2 to continue without debug mode. Enter all letters in lower case!" << " \n";
	cin >> debugMode;
		if (debugMode == 1) 
			cout << "The word to guess is: " << wordToGuess << endl << endl; 

	cout << "Let's begin!: \n";
	initialiseDisplay(lengthOfWord);

	while ((incorrectGuesses < MAX_GUESSES) && (loopStopper == 0))
	{
		cout << endl;
		incorrectGuessReturn = hangMan(wordToGuess, lengthOfWord, flag);
		
		display(lengthOfWord);
		cout << endl;
		if (incorrectGuessReturn == 0)
		{
			incorrectGuesses++;
		}
		else
			cout << "You guessed correctly.\n";

		cout << "Number of incorrect guesses:  " << incorrectGuesses << " \n";
		
		usedLetterBoard = displayLetterBoard();
		cout << "You have used the letters: " << usedLetterBoard << " \n"; 
		
		loopStopper = checkString(lengthOfWord);
		cout << endl;
	}

	if (loopStopper == 1)
		cout << "\n" <<  "Congratulations! You won." << " \n" << " \n"; 

	else if (incorrectGuesses==MAX_GUESSES)
		cout << "Oops! Looks like you used all your guesses. Time to hang your man!" << endl << "The correct word was: " << wordToGuess << endl;

	return 0;
}