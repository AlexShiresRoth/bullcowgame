#pragma once
#include <string>;

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
	
	EGuessStatus CheckGuessValidity(FString) const; 

	void Reset(); //todo make a more rich return value
	
	//provide a method for counting bulls and cows and increasing try number
	//counts bulls and cows and increases try number assuming valid guess

	FBullCowCount SubmitGuess(FString);



private:
	//see constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};