#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input;

    // Set a prompt for the user
    rl_bind_key('\t', rl_complete); // Enable tab-completion
    while ((input = readline("Enter a command: ")) != NULL) {
        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }
        printf("You entered: %s\n", input);
        add_history(input);
        free(input);
    }

    return 0;
}

