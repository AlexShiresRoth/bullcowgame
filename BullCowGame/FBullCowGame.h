#pragma once
#include <string>;

/* 
The game logic(no view code or direct user interaction)
The game is a simple word guessing game based on Mastermind
*/

//dont use namespace in header files

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	INVALID_STATUS,
	OK,
	NOT_ISOGRAM,
	SPECIAL_CHARACTER,
	WRONG_LENGTH,
	NOT_LOWERCASE
};

class FBullCowGame {
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	
	bool IsGameWon() const;
	bool GameIsWon() const;
	
	
	EGuessStatus CheckGuessValidity(FString) const; 

	void Reset(); 
	
	//provide a method for counting bulls and cows and increasing try number
	//counts bulls and cows and increases try number assuming valid guess

	FBullCowCount SubmitValidGuess(FString);



private:
	//see constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;

	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};