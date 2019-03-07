// BullCowGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h" //
#include <iostream>
#include <string>

//std:: is a namespace
using namespace std;

void PrintIntro();
void StartGame();

string GetGuess();

bool AskToPlayAgain();

bool AskToPlayAgain()
{
	cout << "Do you want to play again? y/n" << endl;
	string Response = "";

	getline(cin, Response);

	if (Response[0] == 'y' || Response[0] == 'Y') {

		cout << "True";
		return true;
	}

	cout << "False";

	return false;
}

void PrintIntro() 
{
	//introduce the game
	constexpr int WORD_LENGTH = 5;

	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of? \n";
	cout << endl;
	// get a guess from the player

	return;
}

string GetGuess() {

	cout << "Try and guess: ";

	string Guess = "";

	getline(cin, Guess);

	return Guess;
}

void StartGame() 
{
	constexpr int NUMBER_OF_TURNS = 5;

	for (int count = 0; count < NUMBER_OF_TURNS; count++) {

		 string Guess = GetGuess();

		 cout << "You guessed: " << Guess << endl;
		 
		 cout << endl;
	}
	return;
}

//the entry point for our application
int main()
{
	PrintIntro();

	StartGame();

	AskToPlayAgain();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
