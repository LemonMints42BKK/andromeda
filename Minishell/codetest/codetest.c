/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codetest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g65420029 <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 04:22:24 by g65420029         #+#    #+#             */
/*   Updated: 2023/05/30 04:22:45 by g65420029        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 64
#define DELIMITERS " \t\r\n\a"
#define HISTORY_FILE ".minishell_history"

int history_enabled = 1;

void handle_ctrl_c(int signum) {
    printf("\n");
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

void handle_ctrl_d(int signum) {
    printf("\n");
    exit(EXIT_SUCCESS);
}

void handle_ctrl_backslash(int signum) {
    printf("\n");
    // Do nothing
}

void enable_signals() {
    signal(SIGINT, handle_ctrl_c);
    signal(SIGQUIT, handle_ctrl_backslash);
    signal(SIGTERM, SIG_DFL);
    signal(SIGTSTP, SIG_DFL);
    signal(SIGTTIN, SIG_DFL);
    signal(SIGTTOU, SIG_DFL);
    signal(SIGCHLD, SIG_DFL);
}

void disable_signals() {
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGTERM, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);
    signal(SIGCHLD, SIG_IGN);
}

void read_input(char* input) {
    char* prompt = "minishell> ";
    char* readline_input = readline(prompt);

    if (readline_input == NULL) {
        strcpy(input, "exit"); // Treat Ctrl-D as an exit command
        printf("\n");
        return;
    }

    strncpy(input, readline_input, MAX_INPUT_SIZE - 1);
    input[MAX_INPUT_SIZE - 1] = '\0';

    if (input[0] != '\0' && history_enabled) {
        add_history(input);
        write_history(HISTORY_FILE);
    }

    free(readline_input);
}

int tokenize_input(char* input, char* tokens[]) {
    int token_count = 0;
    char* token = strtok(input, DELIMITERS);

    while (token != NULL) {
        tokens[token_count] = token;
        token_count++;
        token = strtok(NULL, DELIMITERS);
    }

    tokens[token_count] = NULL;
    return token_count;
}

void expand_environment_variables(char* token) {
    char* env_variable = NULL;
    char* expanded_token = NULL;
    size_t token_len = strlen(token);
    size_t expanded_len = 0;

    for (size_t i = 0; i < token_len; i++) {
        if (token[i] == '$') {
            if (token[i + 1] == '?') {
              //  asprintf(&env_variable, "%d", WEXITSTATUS(set_last_command_exit_status()));
                 printf("xx\n");
                expanded_len += strlen(env_variable);
                i++; // Skip the next character since it has been processed
            } else if (isalnum(token[i + 1]) || token[i + 1] == '_') {
                char* start = token + i + 1;

                char* end = strchr(start, '\0');
                size_t var_len = end - start;

                if (var_len > 0) {
                    char env_var[var_len + 1];
                    strncpy(env_var, start, var_len);
                    env_var[var_len] = '\0';

                    char* value = getenv(env_var);
                    if (value != NULL) {
                        expanded_len += strlen(value);
                      //  asprintf(&expanded_token, "%s%s%s", expanded_token, value, end);
                      printf("xx\n");
                    }
                }
            } else {
                expanded_len++;
                expanded_token = strncat(expanded_token, &token[i], 1);
            }
        } else {
            expanded_len++;
            expanded_token = strncat(expanded_token, &token[i], 1);
        }
    }

    if (expanded_token != NULL) {
        strncpy(token, expanded_token, expanded_len);
        token[expanded_len] = '\0';
        free(expanded_token);
    }

    free(env_variable);
}

int execute_command(char* tokens[]) {
    pid_t pid;
    int status;
    int input_fd = 0;
    int output_fd = 1;
    int pipe_fd[2];

    while (*tokens != NULL) {
        if (strcmp(*tokens, "<") == 0) {
            // Input redirection
            tokens++;
            input_fd = open(*tokens, O_RDONLY);
            if (input_fd < 0) {
                perror("input redirection failed");
                return 1;
            }
        } else if (strcmp(*tokens, ">") == 0) {
            // Output redirection
            tokens++;
            output_fd = open(*tokens, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
            if (output_fd < 0) {
                perror("output redirection failed");
                return 1;
            }
        } else if (strcmp(*tokens, ">>") == 0) {
            // Output redirection in append mode
            tokens++;
            output_fd = open(*tokens, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
            if (output_fd < 0) {
                perror("output redirection failed");
                return 1;
            }
        } else if (strcmp(*tokens, "|") == 0) {
            // Pipe
            tokens++;
            pipe(pipe_fd);
            output_fd = pipe_fd[1];
        } else {
            pid = fork();

            if (pid < 0) {
                perror("fork failed");
                return 1;
            } else if (pid == 0) {
                // Child process

                // Set the input/output redirection
                if (input_fd != 0) {
                    dup2(input_fd, 0);
                    close(input_fd);
                }

                if (output_fd != 1) {
                    dup2(output_fd, 1);
                    close(output_fd);
                }

                if (pipe_fd[0] != 0) {
                    dup2(pipe_fd[0], 0);
                    close(pipe_fd[0]);
                    close(pipe_fd[1]);
                }

                // Execute the command
                if (execvp(*tokens, tokens) < 0) {
                    perror("execvp failed");
                    exit(EXIT_FAILURE);
                }
            } else {
                // Parent process

                // Close unused file descriptors
                if (input_fd != 0) {
                    close(input_fd);
                    input_fd = 0;
                }

                if (output_fd != 1) {
                    close(output_fd);


                    output_fd = 1;
                }

                if (pipe_fd[0] != 0) {
                    close(pipe_fd[0]);
                    close(pipe_fd[1]);
                }

                // Wait for the child process to complete
                waitpid(pid, &status, 0);
            }
        }

        tokens++;
    }

    return WEXITSTATUS(status);
}

void execute_builtin_command(char* tokens[]) {
    if (strcmp(tokens[0], "echo") == 0) {
        int i = 1;
        int new_line = 1;

        if (tokens[i] != NULL && strcmp(tokens[i], "-n") == 0) {
            new_line = 0;
            i++;
        }

        while (tokens[i] != NULL) {
            printf("%s", tokens[i]);
            i++;
            if (tokens[i] != NULL) {
                printf(" ");
            }
        }

        if (new_line) {
            printf("\n");
        }
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1] == NULL) {
            char* home_dir = getenv("HOME");
            if (home_dir != NULL) {
                chdir(home_dir);
            }
        } else {
            if (chdir(tokens[1]) != 0) {
                perror("cd failed");
            }
        }
    } else if (strcmp(tokens[0], "pwd") == 0) {
        char cwd[MAX_INPUT_SIZE];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s\n", cwd);
        } else {
            perror("pwd failed");
        }
    } else if (strcmp(tokens[0], "export") == 0) {
        // TODO: Implement export command
        printf("export command is not yet implemented.\n");
    } else if (strcmp(tokens[0], "unset") == 0) {
        // TODO: Implement unset command
        printf("unset command is not yet implemented.\n");
    } else if (strcmp(tokens[0], "env") == 0) {
        // TODO: Implement env command
        printf("env command is not yet implemented.\n");
    } else if (strcmp(tokens[0], "exit") == 0) {
        exit(EXIT_SUCCESS);
    } else {
        printf("Unknown command: %s\n", tokens[0]);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char* tokens[MAX_TOKENS];
    int token_count;

    enable_signals();

    // Load history from file
    read_history(HISTORY_FILE);

    while (1) {
        read_input(input);

        token_count = tokenize_input(input, tokens);

        // Expand environment variables
        for (int i = 0; i < token_count; i++) {
            expand_environment_variables(tokens[i]);
        }

        if (token_count > 0) {
            if (strcmp(tokens[0], "exit") == 0) {
                exit(EXIT_SUCCESS);
            } else if (strcmp(tokens[0], "history") == 0) {
                history_enabled = !history_enabled;
                printf("History %s\n", history_enabled ? "enabled" : "disabled");
            } else if (strcmp(tokens[0], "!!") == 0) {
                HIST_ENTRY* entry = history_get(history_length);
                if (entry != NULL) {
                    strcpy(input, entry->line);
                    printf("%s\n", input);
                    token_count = tokenize_input(input, tokens);
                    execute_builtin_command(tokens);
                } else {
                    printf("No previous command found in history.\n");
                }
            } else {
                pid_t pid = fork();

                if (pid < 0) {
                    perror("fork failed");
                } else if (pid == 0) {
                    // Child process
                    disable_signals();

                    // Execute built-in commands
                    execute_builtin_command(tokens);

                    // Execute external commands
                    int status = execute_command(tokens);
                    printf("xx\n");
                    //set_last_command_exit_status(status);

                    enable_signals();
                    exit(status);
                } else {
                    // Parent process
                    int status;
                    waitpid(pid, &status, 0);

                    // Set the exit status of the last command
                    printf("xx\n");
                   // set_last_command_exit_status(WEXITSTATUS(status));
                }
            }
        }
    }

    return 0;
}

