// BullCowGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/* This is the console executable, that makes use of BullCowGame class 
This acts as the view in a MVC pattern, and is responsible for all user interaction.
For game logic see the FBullCowGame class.*/

#include "pch.h" //
#include <iostream>
#include <string>
#include "FBullCowGame.h"

//std:: is a namespace
using FText = std::string;
using int32 = int;

void PrintIntro();
void StartGame();

FText GetGuess();

bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new games

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)" << std::endl;

	FText Response = "";

	getline(std::cin, Response);

	if (Response[0] == 'y' || Response[0] == 'Y') {

		std::cout << "True";
		return true;
	}

	std::cout << "False";

	return false;
}

void PrintIntro() 
{
	//introduce the game

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
	// get a guess from the player

	return;
}

FText GetGuess() {

	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout <<"Try" << CurrentTry << ". " << "Enter your guess: ";

	FText Guess = "";

	getline(std::cin, Guess);

	return Guess;
}

void StartGame() 
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();
	//TODO change for to while loop when we are validating tries 
	for (int32 count = 0; count < MaxTries; count++) {

		 FText Guess = GetGuess();//TODO make loop check for valid guess

		 EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

		 //Submit valid gues to the game
		 FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		 //Print number of bulls of cows
		 std::cout << "Bulls =  " << BullCowCount.Bulls << std::endl;
		 std::cout << ". Cows =  " << BullCowCount.Cows << std::endl;
		 
		 std::cout << std::endl;
	}
	return;
}

//the entry point for our application
int main()
{
	bool bPlayAgain = false;

	do{
		PrintIntro();

		StartGame();
		//TODO add game summary
		bPlayAgain = AskToPlayAgain();
	// will continue to play as long as the function result returns true
	} while (bPlayAgain);

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
