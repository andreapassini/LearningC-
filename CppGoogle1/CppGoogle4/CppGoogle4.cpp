#include <iostream>

constexpr auto max_size = std::numeric_limits<std::streamsize>::max();

int GenerateAnInt(int upperLimit, int loweLimit)
{
    return rand() % upperLimit + loweLimit;
}

int main(int argc, char* argv[])
{
    std::cout << "Welcome to the guessing game" << std::endl;
    std::cout << std::endl << "--- Guess the int number between 1 and 100 --- \t" << std::endl;

    // Generate number
    int numberToGuess = GenerateAnInt(100, 1);
    std::cout << numberToGuess;
    int playerGuess = 0;
    std::cout << "\t The NUMBER has been generated" << std::endl;
    std::cout << "\t Let the Guessing game begin" << std::endl;

    do
    {
        if (!(std::cin >> playerGuess))
        {
            std::cout << "You entered a non-numeric" << std::endl;
            std::cin.ignore();
            std::cin.clear();
            std::cin.ignore(max_size, '\n'); // skip bad input    } while(numberToGuess != playerGuess);
            continue;
        }
        
        if(playerGuess < numberToGuess)
        {
            std::cout << " -- that's too LOW --" << std::endl;
            std::cout << "\t TRY AGAIN" << std::endl;
        }
        else if(playerGuess > numberToGuess)
        {
            std::cout << " -- that's too HIGH --" << std::endl;
            std::cout << "\t TRY AGAIN" << std::endl;
        }
    } while (numberToGuess != playerGuess);
    std::cout << std::endl << " \t YOU WON - Random Number is " << numberToGuess << std::endl << std::endl;
    std::cout << "Press any key to exit" << std::endl;

    // Wait one last key to exit the program
    std::cin.get();
    
    return 0;
}
