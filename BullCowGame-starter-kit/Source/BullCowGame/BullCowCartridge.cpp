// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
	Super::BeginPlay();

	SetupGame();
	//	PrintLine(FString::Printf(TEXT("CHEAT the word is %s and it is %i characters long"), *HiddenWord, HiddenWord.Len()));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
	//ClearScreen();

	if (bGameOver)
	{
		ClearScreen();
		SetupGame();
	}
	else {
		ProcessGuess(Input);
	}
}

void UBullCowCartridge::ShowWelcomeMessage()
{

	PrintLine(TEXT("Hello!"));
	PrintLine(TEXT("Press Tab to start writing"));
	PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
	PrintLine(TEXT("You have %i lives"), Lives);
	PrintLine(TEXT("Write your guess and press enter"));
}

void UBullCowCartridge::SetupGame()
{
	bGameOver = false;
	HiddenWord = TEXT("dupa");
	Lives = HiddenWord.Len();

	ShowWelcomeMessage();
}

void UBullCowCartridge::EndGame(bool bResult)
{
	bGameOver = true;
	ClearScreen();
	if (!bResult)
	{
		PrintLine(TEXT("You don't have lives, you lost"));
		PrintLine(TEXT("Answear was: %s"), *HiddenWord);
	}
	PrintLine(TEXT("Press Enter to restart"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
	if (Guess == HiddenWord)
	{
		PrintLine(TEXT("You Have won"));
		EndGame(true);
		return;
	}

	if ((Guess.Len() != HiddenWord.Len()))
	{
		PrintLine(TEXT("word length is %i, try again "), HiddenWord.Len());
		return;
	}

	if (!IsIsogram(Guess))
	{
		PrintLine(TEXT("No repeating letters, try again"));
		return;
	}

	PrintLine(TEXT("Wrong, lost live, you have %i "), --Lives);

	if (Lives <= 0)
	{
		EndGame(false);
		return;
	}

	//Show bulls and cows
}

bool UBullCowCartridge::IsIsogram(FString Word) const
{
	for (int32 i = 0; i < Word.Len(); i++)
	{
		for (int32 j = i + 1; j < Word.Len(); j++)
		{
			if (Word[i] == Word[j])
				return false;
		}
	}
	return true;
}