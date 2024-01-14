#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    int randomNumber = rand() % 100 + 1;
    int userGuess;
    bool guessed = false;

    std::cout << "Guess the number between 1 and 100!" << std::endl;

    while (!guessed) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (userGuess == randomNumber) {
            guessed = true;
            std::cout << "Yayy.. You guessed the correct number!" << std::endl;
        } else if (userGuess > randomNumber) {
            std::cout << "Your guess is too high...Try again." << std::endl;
        } else {
            std::cout << "Your guess is too low...Try again." << std::endl;
        }
    }

    return 0;
}
