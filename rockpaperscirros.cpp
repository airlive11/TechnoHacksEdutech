/**
 * Technohacks Internship C++ Programming
 * Task number - 03
 * Task name - Rock Paper Scissors
 * 
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//Get the choice for ROCK , PAPER AND SCISSORS
enum class Choice { ROCK, PAPER, SCISSORS };

Choice getUserChoice() {
    int choice;
    cout << "Enter your choice:\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";
    cout << "Your choice (1/2/3): ";
    cin >> choice;
    /*
        choice --> 1 for ROCK
        choice --> 2 for PAPER
        choice --> 3 for SCISSORS
    */
    switch (choice) {
        case 1:
            return Choice::ROCK; 
        case 2:
            return Choice::PAPER;
        case 3:
            return Choice::SCISSORS;
        default:
            cout << "Invalid choice. Please try again.\n";
            return getUserChoice();
    }
}

Choice getComputerChoice() {
    int randomChoice = rand() % 3; // Generates random number between 0 and 2

    switch (randomChoice) {
        case 0:
            return Choice::ROCK;
        case 1:
            return Choice::PAPER;
        case 2:
            return Choice::SCISSORS;
    }

    return Choice::ROCK; // Default return, should never reach here
}

void determineWinner(Choice userChoice, Choice computerChoice) {
    std::cout << "Computer chose: ";
    switch (computerChoice) {
        case Choice::ROCK:
            std::cout << "Rock\n";
            break;
        case Choice::PAPER:
            std::cout << "Paper\n";
            break;
        case Choice::SCISSORS:
            std::cout << "Scissors\n";
            break;
    }

    if (userChoice == computerChoice) {
        cout << "It's a tie!\n";
    } else if (
        (userChoice == Choice::ROCK && computerChoice == Choice::SCISSORS) ||
        (userChoice == Choice::PAPER && computerChoice == Choice::ROCK) ||
        (userChoice == Choice::SCISSORS && computerChoice == Choice::PAPER)
    ) {
        cout << "You win!\n";
    } else {
        cout << "Computer wins!\n";
    }
}

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    cout << "Welcome to Rock, Paper, Scissors!\n";

    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        Choice userChoice = getUserChoice();
        Choice computerChoice = getComputerChoice();

        determineWinner(userChoice, computerChoice);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thank you for playing!\n";

    return 0;
}

