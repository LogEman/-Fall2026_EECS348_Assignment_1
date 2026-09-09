//EECS 348 Assignment 1
//C program that picks a secret number between 1 and 10.
//The user gets up to 3 tries to guess the number.
//Inputs: The users guess via terminal
//Output: correct (or incorrect guess) via terminal
//ChatGPT, Gemini
//Logan Kessler

#include <stdio.h>

int main() {
    int secretNumber = 7;
    int guess;
    int attempts = 0;
    int correct = 0;

    printf("Guess a number between 1 and 10.\n");

    while (attempts < 3) {
        attempts++;

        printf("Attempt %d/3. Enter your guess: ", attempts);
        scanf("%d", &guess);

        if (guess == secretNumber) {
            printf("Correct! You win!\n");
            correct = 1;
            break;
        } else if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }
    }

    if (!correct) {
        printf("You lose! The secret number was %d.\n", secretNumber);
    }

    return 0;
}
