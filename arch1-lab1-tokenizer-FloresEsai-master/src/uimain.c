#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tokenizer.h>
#include <history.h>

#define MAX_INPUT_SIZE 100

int main() {
    char input[MAX_INPUT_SIZE];
    List* history = init_history();

    while (1) {
        printf("\nEnter one of the following:\n");
        printf("1. 'q' to quit\n");
        printf("2. 'w' to type a sentence\n");
        printf("3. '!' followed by how far you would like to go back\n");
        printf("4. 'h' for the history of the program\n");
        printf("$");

        if (!fgets(input, MAX_INPUT_SIZE, stdin)) {
            printf("exiting now\n");
            free_history(history);
            return 0;
        }

        input[strcspn(input, "\n")] = 0; // remove newline character

        switch (input[0]) {
        case 'q':
            printf("exiting now\n");
            free_history(history);
            return 0;
        case 'w':
            printf("Please enter your sentence:\n$");
            if (!fgets(input, MAX_INPUT_SIZE, stdin)) {
                printf("exiting now\n");
                free_history(history);
                return 0;
            }
            char** tokens = tokenize(input);
            print_tokens(tokens);
            add_history(history, input);
            free_tokens(tokens);
            break;
        case '!':
            printf("Retrieved history: %s\n", get_history(history, atoi(input + 1)));
            break;
        case 'h':
            print_history(history);
            break;
        default:
            printf("enter a valid answer\n");
        }
    }
}