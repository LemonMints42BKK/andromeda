/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g65420029 <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 06:18:17 by g65420029         #+#    #+#             */
/*   Updated: 2023/05/06 07:12:20 by kanit_c          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "minishell.h"

#define MAX_CMD_LENGTH 100

int main() {
    char cmd[MAX_CMD_LENGTH];
    char *args[MAX_CMD_LENGTH];
    char *token;
    int status;

    while (1) {
        ft_printf("Andromeda$ ");  // Display prompt
        fgets(cmd, MAX_CMD_LENGTH, stdin);  // Read user input
        cmd[strcspn(cmd, "\n")] = '\0';  // Remove trailing newline

        // Tokenize input into arguments
        int arg_index = 0;
        token = strtok(cmd, " ");
        while (token != NULL) {
            args[arg_index++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_index] = NULL;

        // Exit shell if "exit" command is entered
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        }

        // Fork a child process to execute external commands
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            // Child process
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(1);
            }
        } else {
            // Parent process
            if (waitpid(pid, &status, 0) == -1) {
                perror("waitpid");
                exit(1);
            }
        }
    }

    return 0;
}


