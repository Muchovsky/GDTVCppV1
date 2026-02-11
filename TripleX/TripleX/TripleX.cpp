#include <iostream>
# include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "You are a secret agent braking into a level " << Difficulty << " secure server room" << '\n';
    std::cout << "You need to enter the correct codes to continue ... " << '\n';
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    int modDiff = Difficulty + Difficulty;
    const int CodeA = rand() %  Difficulty + Difficulty;
    const int CodeB = rand() %  Difficulty + Difficulty;
    const int CodeC = rand() %  Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    std::cout << " + There are 3 numbers in code" << '\n';
    std::cout << " + Code sum is: " << CodeSum << '\n';
    std::cout << " + Code multiplication is: " << CodeProduct << '\n';
    int GuessA, GuessB, GuessC, GuessSum, GuessProduct;

    std::cout << "Enter 3 numbers  " << '\n';
    std::cin >> GuessA >> GuessB >> GuessC;
    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You entered the correct code!" << '\n';
        return true;
    }

    std::cout << "You entered an invalid code! Try Again!" << '\n';
    return false;
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 10;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);

        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            LevelDifficulty++;
        }
    }

    std::cout << "You win the game!" << '\n';

    return 0;
}
