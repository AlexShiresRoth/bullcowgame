#pragma once

#include "pch.h"
#include "FBullCowGame.h"

//to make syntax Unreal friendly
#include <map>
#define TMap std::map 

int32 FBullCowGame::GetMaxTries () const
{
	//wordlength to max tries
	TMap<int32, int32> WordLengthToMaxTries{ {3, 4}, {4, 6}, {5, 10}, {6, 15} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

bool FBullCowGame::GameIsWon() const
{
	return IsGameWon();
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{

	if (!IsIsogram(Guess))//if the guess isn't an isogram,
	{
		return EGuessStatus::NOT_ISOGRAM;
	}
	else if (!IsLowerCase(Guess))// if the guess isnt all lowercase return an error  
	{
		return EGuessStatus::NOT_LOWERCASE; //TODO write function
	}
	else if(Guess.length() != GetHiddenWordLength())//if the guess length is wrong
	{
		return EGuessStatus::WRONG_LENGTH;
	}
	else //otherwise return ok
	{
		return EGuessStatus::OK;
	}
	 
	
}

//receives a valid guess, increments turn and returns count 
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	
	FBullCowCount BullCowCount;
	// loop through all letters in the hidden word
	int32 WordLength = MyHiddenWord.length();


	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		//compare letters against the hidden word
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			//if they match then
			if (Guess[MHWChar] == MyHiddenWord[GChar])
			{
				//increment bulls if they're in the same place
				if (MHWChar == GChar) 
				{
					BullCowCount.Bulls++;
					//increment cows if not
				}
				else 
{
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0  and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }
	
	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) //for all letters of the word
		{
		Letter = tolower(Letter);
		if(LetterSeen[Letter])
		{
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}
		//if the letter is in the map
			//we do not have an isogram
		//otherwise
			//add the letter to the map as seen
		}
	return true;//in case where /0 is entered
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterLower;
	for(auto Letter : Word) { //: mean "in" in a loop
	

		if (!islower(Letter)) {
			return false;
		}
		else {
			return LetterLower[Letter] = true;
		}
	}
	return true;
}

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet"; //this must be an isogram
	
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	MyCurrentTry = 1;
	return;
}

