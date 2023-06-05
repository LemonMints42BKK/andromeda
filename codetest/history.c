#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char* input = readline("Enter your name: ");
    add_history(input);
    printf("Hello, %s!\n", input);
    free(input);
    rl_clear_history();
    rl_on_new_line();
    rl_replace_line("New input", 1);
    rl_redisplay();
    return 0;
}
