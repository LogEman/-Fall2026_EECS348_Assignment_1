//EECS 348 Assignment 1
//C program that picks a secret number between 1 and 10.
//The user gets up to 3 tries to guess the number.
//Inputs: The users guess via terminal
//Output: correct (or incorrect guess) via terminal
//ChatGPT, Gemini
//Logan Kessler
#include <stdio.h>

int main() {
    int secret = 7;          // Fixed secret number
    int guess;
    int max_tries = 3;
    int won = 0;             // Flag to track if the user won

    printf("Guess a number between 1 and 10.\n");

    // Loop to give the user up to 3 tries
    for (int i = 1; i <= max_tries; i++) {
        printf("Attempt %d/%d. Enter your guess: ", i, max_tries);
        scanf("%d", &guess);

        // Check if the guess is correct, too high, or too low
        if (guess == secret) {
            printf("Correct! You win!\n");
            won = 1;
            break; // Stop the loop immediately on a correct guess
        } else if (guess < secret) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }
    }

    // Print final lose message if the user ran out of tries without winning
    if (!won) {
        printf("You ran out of tries! You lose. The secret number was %d.\n", secret);
    }

    return 0;
}
