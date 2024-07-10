// CodSoft Internship
// Domain Name - C++ Programming
// Task - 2 (Number Guessing)
// Intern Name - Surya Pratap Singh

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // Include limits for numeric_limits

using namespace std;

void guessTheNumber() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    int numberToGuess = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess = 0;
    int lowerBound = 1;
    int upperBound = 100;

    cout << "\nWelcome to the Guess the Number game!" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;

    while (guess != numberToGuess) {
        cout << "\nEnter your guess: ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. 🚫 Please enter a valid number." << endl;
            continue;
        }

        if (guess < numberToGuess) {
            cout << "Too low! Try again." << endl;
            // cout << "The correct number is: " << numberToGuess << endl;
            if (guess > lowerBound) lowerBound = guess + 1;
        } else if (guess > numberToGuess) {
            cout << "Too high! Try again." << endl;
            // cout << "The correct number is: " << numberToGuess << endl;
            if (guess < upperBound) upperBound = guess - 1;
        } else {
            cout << "\nCongratulations! 🎉🥂🍾✨ You've guessed the correct number: " << numberToGuess << endl;
            break;
        }

        // cout << "Hint: The number is between " << lowerBound << " and " << upperBound << "." << endl;
    }
}

int main() {
    guessTheNumber();
    return 0;
}