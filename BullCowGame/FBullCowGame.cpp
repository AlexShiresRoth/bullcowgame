#include "pch.h"
#include "FBullCowGame.h"

int32 FBullCowGame::GetMaxTries () const
{
	return MyMaxTries;
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
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)//if the guess isn't an isogram,
	{
		return EGuessStatus::NOT_ISOGRAM;
	}
	else if (false)// if the gues sisnt all lowercase return an error
	{
		return EGuessStatus::NOT_LOWERCASE;
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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment a turn number
	MyCurrentTry++;
	//setup a return variable
	FBullCowCount BullCowCount;
	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();


	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		//compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
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
	return BullCowCount;
}

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	return;
}

