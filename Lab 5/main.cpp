/*
	Delvis Kouete
	Computer Science Fall 2024
	Due: Nov. 12, 2024
	Lab 5, Lab 5 Number Guessing Game
	Write a number-guessing game in which the computer selects a random
	number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At
	the end of each game, users should be told whether they won or lost, and then be asked
	whether they want to play again. 
	*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

// Class to handle the game logic
class NumberGuessingGame 
{
private:
    int targetNumber;          // The number to guess
    int maxAttempts = 20;      // Maximum number of attempts allowed
    int attemptsLeft;          // Number of attempts remaining
    bool gameWon;              // Whether the player has won
    vector<string> winMessages;
    vector<string> loseMessages;
    vector<string> playAgainMessages;

public:
    // Constructor
    NumberGuessingGame() 
    {
        // Seed random number generator
        srand(time(0));

        // Initialize the win, lose, and play again messages
        winMessages = 
        {
            "Awesome! You nailed it!"
            "You did it! The correct number was indeed the one you picked."
            "Well done! You've got it!"
            "Amazing! You've guessed it right."
            "Great job! You were spot on!"
            "Perfect! The number is a match."
            "Bravo! You've successfully guessed the number."
            "Victory is yours! The number was correct."
            "You rock! You've guessed the right number."
            "Congratulations, you guessed the right number!"
        };

        loseMessages = 
        {
            "Better luck next time! The number was "
            "Oops, no more guesses left! The number was "
            "Tough luck! The number was "
            "Unfortunately, you're out of attempts. It was "
            "You failed to guess the number. It was "
            "Alas, you couldn’t guess the number. It was "
            "Game over! The correct number was "
            "Try again next time! The number was "
            "Sorry, you ran out of attempts. The number was "
            "Oh no, no more guesses! The number was "
        };

        playAgainMessages = 
        {
           "Want to try again? (y/n): "
           "How about a rematch? (y/n): "
           "Do you want to give it another shot? (y/n): "
           "Are you up for another round? (y/n): "
           "Ready for another round? (y/n): "
           "Play again? (y/n): "
           "Would you like to play another round? (y/n): "
           "Another game? (y/n): "
           "Do you want to play again? (y/n): "
           "Feel like playing again? (y/n): "
        };
    }

    // Start a new game
    void startGame() 
    {
        // Select a random number between 0 and 100
        targetNumber = rand() % 101;
        attemptsLeft = maxAttempts;
        gameWon = false;
        int playerGuess;

        cout << "I have selected a number between 0 and 100. Try to guess it!" << endl;

        // Main game loop (do-while)
        do 
        {
            cout << "You have " << attemptsLeft << " attempts left." << endl;
            cout << "Enter your guess: ";
            cin >> playerGuess;

            if (playerGuess < targetNumber) 
            {
                cout << "Too low!" << endl;
            }
            else if (playerGuess > targetNumber) 
            {
                cout << "Too high!" << endl;
            }
            else 
            {
                gameWon = true;
                break;
            }

            attemptsLeft--;
        } while (attemptsLeft > 0 && !gameWon);

        // After the game ends, output the result
        if (gameWon) 
        {
            // Randomly select a win message
            int winIndex = rand() % winMessages.size();
            cout << winMessages[winIndex] << endl;
        }
        else 
        {
            // Randomly select a lose message and reveal the number
            int loseIndex = rand() % loseMessages.size();
            cout << loseMessages[loseIndex] << targetNumber << endl;
        }
    }

    // Ask the player if they want to play again
    bool askToPlayAgain() 
    {
        // Randomly select a play-again prompt
        int playAgainIndex = rand() % playAgainMessages.size();
        char response;
        cout << playAgainMessages[playAgainIndex];
        cin >> response;

        // Return true if the player wants to play again, false otherwise
        return (response == 'y' || response == 'Y');
    }
};

int main() 
{
    NumberGuessingGame game;
    int wins = 0;
    int losses = 0;

    do 
    {
        game.startGame();

        // Check if the player won or lost
        if (game.askToPlayAgain()) 
        {
            // Player wants to play again
            continue;
        }
        else 
        {
            // Player doesn't want to play again, break the loop
            break;
        }

    } while (true);

    // At the end of all games, display the number of wins and losses
    cout << "Thanks for playing!" << endl;
    cout << "Total Wins: " << wins << endl;
    cout << "Total Losses: " << losses << endl;

    return 0;
}

