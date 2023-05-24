/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlnsample2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g65420029 <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:45:11 by g65420029         #+#    #+#             */
/*   Updated: 2023/05/06 13:45:20 by g65420029        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

int main()
{
    char* input;
    char* cmd;
    char* args[20];
    int arg_count;

    while (1)
    {
        input = readline("Andromeda$ ");
        add_history(input);

        // Tokenize the input string
        cmd = strtok(input, " \t\n\r");
        arg_count = 0;
        while (cmd != NULL && arg_count < 20)
        {
            args[arg_count] = cmd;
            arg_count++;
            cmd = strtok(NULL, " \t\n\r");
        }
        args[arg_count] = NULL;

        if (arg_count > 0)
        {
            // Handle built-in commands
            if (strcmp(args[0], "exit") == 0)
            {
                exit(0);
            }
            else if (strcmp(args[0], "cd") == 0)
            {
                if (arg_count > 1)
                {
                    chdir(args[1]);
                }
                else
                {
                    chdir(getenv("HOME"));
                }
            }
            else if (strcmp(args[0], "pwd") == 0)
            {
                char cwd[MAX_CMD_LEN];
                if (getcwd(cwd, sizeof(cwd)) != NULL)
                {
                    printf("%s\n", cwd);
                }
            }
            else
            {
                // Handle external commands
                pid_t pid = fork();
                if (pid == 0)
                {
                    // Child process
                    execvp(args[0], args);
                    perror("execvp failed");
                    exit(1);
                }
                else if (pid < 0)
                {
                    perror("fork failed");
                }
                else
                {
                    // Parent process
                    wait(NULL);
                }
            }
        }

        free(input);
    }

    return 0;
}

