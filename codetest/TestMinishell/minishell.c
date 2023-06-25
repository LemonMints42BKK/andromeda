/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 04:36:24 by kchatvet          #+#    #+#             */
/*   Updated: 2023/06/25 01:20:40 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
    char cmd[MAX_CMD_LENGTH];
    char *args[MAX_CMD_LENGTH];
    char *token;
    int status;

    my_read_history();
    while (1)
    {
        myfgets(cmd, MAX_CMD_LENGTH, stdin);  // Read user input
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
            rl_clear_history();
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
    return (0);
}
