// BullCowGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h" //
#include <iostream>
#include <string>

//std:: is a namespace
using namespace std;

int main()
{
	//introduce the game
	constexpr int WORD_LENGTH = 5;
	
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of? \n";
	cout << endl;
	// get a guess from the player

	cout << "Try and guess!\n";

	string Guess = "";

	cin >> Guess;

	cout << "You guessed " << Guess;

	//repeat the guess back to them

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
