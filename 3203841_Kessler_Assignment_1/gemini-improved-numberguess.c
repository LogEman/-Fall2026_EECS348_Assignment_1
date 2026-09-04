#include <stdio.h>

int main() {
    int secret = 7;           // Fixed secret number
    int guess;
    int max_tries = 3;
    int won = 0;               // Flag to track if the user won

    printf("Guess a number between 1 and 10.\n");

    // Loop to give the user up to 3 tries
    for (int i = 1; i <= max_tries; i++) {
        printf("Attempt %d/%d. Enter your guess: ", i, max_tries);

        // scanf returns the number of successfully matched items.
        // If it's not 1, the user didn't enter a valid integer.
        int result = scanf("%d", &guess);

        if (result != 1) {
            printf("Invalid input. Please enter a whole number.\n");

            // Clear the bad input from the buffer so it doesn't
            // get re-read on the next loop iteration, causing an
            // infinite loop of failed scans.
            while (getchar() != '\n' && !feof(stdin)) {
                // discard characters until end of line
            }

            i--; // Don't count this as a used attempt
            continue;
        }

        // Check that the guess is within the stated range
        if (guess < 1 || guess > 10) {
            printf("Please guess a number between 1 and 10.\n");
            i--; // Don't count this as a used attempt either
            continue;
        }

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