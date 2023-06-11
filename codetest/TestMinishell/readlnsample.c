/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlnsample.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g65420029 <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:34:04 by g65420029         #+#    #+#             */
/*   Updated: 2023/05/06 13:34:18 by g65420029        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_CMD_LEN 1024

int main() {
    char *cmd;
    char *args[MAX_CMD_LEN / 2 + 1];
    int should_run = 1;

    while (should_run) {
        // Get command input from user
        cmd = readline("Andromeda$ ");

        // Parse command into arguments
        char *arg = strtok(cmd, " ");
        int i = 0;
        while (arg != NULL && i < MAX_CMD_LEN / 2 + 1) {
            args[i] = arg;
            i++;
            arg = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Execute command
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror("execvp failed");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            wait(NULL);
        }

        // Add command to history
        add_history(cmd);

        // Free allocated memory
        free(cmd);
    }

    return 0;
}

