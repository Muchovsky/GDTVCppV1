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
		if (Input == HiddenWord)
		{
			PrintLine(TEXT("Right"));
			EndGame();
		}
		else
		{
			if ((Input.Len() != HiddenWord.Len()))
			{

				PrintLine(TEXT("word length is %i"), HiddenWord.Len());
				return;
			}
			PrintLine(TEXT("Wrong"));
			EndGame();
		}
	}


	//check length
	//check if isogram
	//change input to all lowercase 
	//compare words

	//substract live

	//check lives count >0
	//if >0 guess again show life left// end game  show word

	//play again?

}

void UBullCowCartridge::ShowWelcomeMessage()
{

	PrintLine(TEXT("Hello!"));
	PrintLine(TEXT("Press Tab to start writing"));
	PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
	PrintLine(TEXT("Write your guess and press enter"));
}

void UBullCowCartridge::SetupGame()
{
	bGameOver = false;
	HiddenWord = TEXT("dupa");
	Lives = 5;

	ShowWelcomeMessage();
}

void UBullCowCartridge::EndGame()
{
	bGameOver = true;


	PrintLine(TEXT("Press Enter to restart"));

}