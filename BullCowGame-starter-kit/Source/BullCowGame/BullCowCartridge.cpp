// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
	Super::BeginPlay();
	ShowWelcomeMessage();
	HiddenWord = TEXT("dupa");

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
	ClearScreen();


	if (Input == HiddenWord)
	{
		PrintLine(TEXT("Right"));
	}
	else
	{
		PrintLine(TEXT("Wrong"));
	}


}

void UBullCowCartridge::ShowWelcomeMessage()
{

	PrintLine(TEXT("Hello!"));
	PrintLine(TEXT("Press Tab to start writing"));
	PrintLine(TEXT("Guess the 4 letter word")); //TODO magic number
	PrintLine(TEXT("Write your guess and press enter"));
}