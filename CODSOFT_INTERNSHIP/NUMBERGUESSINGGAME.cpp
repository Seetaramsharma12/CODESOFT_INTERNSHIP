#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); 
    int numberToGuess = std::rand() % 100 + 1; 
    int playerGuess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100." << std::endl;

    // Game loop
    while (playerGuess != numberToGuess) {
        std::cout << "Enter your guess: ";
        std::cin >> playerGuess;
        attempts++;

        if (playerGuess < numberToGuess) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (playerGuess > numberToGuess) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the number " << numberToGuess << " in " << attempts << " attempts!" << std::endl;
        }
    }

    return 0;
}