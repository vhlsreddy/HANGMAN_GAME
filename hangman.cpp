#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

const int MAXIMUM_TRIES=5;

int Filling_letters (char guess, string unknown_word, string &guessedword)
{
	int i;
	int matched=0;
	int size=unknown_word.length();
	for (i = 0; i< size; i++)
	{
		// check if match this letter in a previous guess?
		if (guess == guessedword[i])
			return 0;
		// check if  the guess in the unknown word?
		if (guess == unknown_word[i])
		{
			guessedword[i] = guess;
			matched++;
		}
	}
	return matched;}

int main ()
{
	string name;
	char letter;
	int wrong_guesses=0;
	string word;
	string list[] =
	{
		"White", "Black", "Grey", "Yellow" ,"Red" ,"Blue", "Green", "Brown", "Pink", "Orange", "Purple"
	};

	//choose a word from array of words(list) randomly
	srand(time(NULL));
	int n=rand()% 11;
	word=list[n];
    
	// Initialize the unknown word with the * character.
	string unknown(word.length(),'*');


	cout << "\n\nWelcome to hangman...Guess a color Name";
	cout << "\n\nEach letter is represented by a underscore.";
	cout<<"\n\nUse only lower case letters!!";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAXIMUM_TRIES << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    
	// Loop until the guesses are used up
	while (wrong_guesses < MAXIMUM_TRIES)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (Filling_letters(letter, word, unknown)==0)
		{
			cout << endl << " That letter isn't in there!Try again" << endl;
			wrong_guesses++;
		}
		else
		{
			cout << endl << " Hurray! You found a letter " << endl;
		}
		// Tell user how many guesses has left.
		cout << "You have " << MAXIMUM_TRIES - wrong_guesses;
		cout << " guesses left." << endl;
		// Check if user guessed the word.
		if (word==unknown)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}
	}
	if(wrong_guesses == MAXIMUM_TRIES)
	{
		cout << "\nSorry, you lose...you've been hanged \"|" << endl;
		cout << "The word was : " << word << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}



