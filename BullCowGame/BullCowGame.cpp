// BullCowGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/* This is the console executable, that makes use of BullCowGame class 
This acts as the view in a MVC pattern, and is responsible for all user interaction.
For game logic see the FBullCowGame class.*/
#pragma once

#include "pch.h" //
#include <iostream>
#include <string>
#include "FBullCowGame.h"


//std:: is a namespace
using FText = std::string; //FText is used in unreal engine coding standards
using int32 = int; //int32 is used in unreal coding standards

//function prototypes as outside a class
void PrintIntro();
void StartGame();
void PrintGameSummary();

FText GetValidGuess();

bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game from the class 

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same word? (y/n) \n\n";

	FText Response = "";

	getline(std::cin, Response);

	if (Response[0] == 'y' || Response[0] == 'Y') {

		return true;
	}

	std::cout << "Goodbye!" << std::endl;

	return false;
}

void PrintIntro() 
{
	//introduce the game
	std::cout << "\n\n Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
	// get a guess from the player

	return;
}

FText GetValidGuess() {

	FText Guess = "";
	EGuessStatus Status = EGuessStatus::INVALID_STATUS;

	do {
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try" << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". " << "Enter your guess: ";
		getline(std::cin, Guess);

		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::WRONG_LENGTH:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n\n";
			break;

		case EGuessStatus::NOT_ISOGRAM:
			std::cout << "Please enter an Isogram(a word without repeating letters)" << "\n\n";
			break;

		case EGuessStatus::NOT_LOWERCASE:
			std::cout << "Pleae use lowercase" << "\n\n";
			break;

		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);//keep looping until we get no errors
	return Guess;
}

//plays a single game to completion
void StartGame() 
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	//loop asking for guesses while the game is not won
	//and there are still tries remaining
	//TODO change for to while loop when we are validating tries 

	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {

		 FText Guess = GetValidGuess();//TODO make loop check for valid guess
		

		 //Submit valid gues to the game
		 FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		 
		 std::cout << "Bulls =  " << BullCowCount.Bulls << std::endl;
		 std::cout << ". Cows =  " << BullCowCount.Cows << "\n\n";
		 
		 std::cout << std::endl;
	}
	return;
}

void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "Congrats! you win. \n" << std::endl;
	}
	else {
		std::cout << "Better luck next time champ! \n" << std::endl;
	}
}
//the entry point for our application
int main()
{
	bool bPlayAgain = false;

	do{
		PrintIntro();

		StartGame();
		//TODO add game summary
		PrintGameSummary();

		bPlayAgain = AskToPlayAgain();
	// will continue to play as long as the function result returns true
	} while (bPlayAgain);

	return 0;
}
