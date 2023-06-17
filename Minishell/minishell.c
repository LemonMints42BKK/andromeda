/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 06:18:17 by pnopjira         #+#    #+#             */
/*   Updated: 2023/05/06 07:12:20 by kanit_c          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    set_zero(t_data *path);
void    free_all(t_data *path)

int     main(void)
{
    t_data *path;

    path = (t_data *)malloc(sizeof(t_data));
    if (!path)
    {   
        perror("Error: malloc failed");
        return (EXIT_FAILURE);
    }
    set_zero(path);
    andro_rd_history();
    while (1)
    {
        if (!myfgets(path->cmd, MAX_CMD_LENGTH, stdin))  // Read user input
            perror("Error");
        if (ft_strchr(path->cmd, '\n'))  // Remove trailing newline
            *ft_strchr(path->cmd, '\n') = '\0';
        andro_parsing(path);//Tokenize input into arguments

        // path->args[arg_index] = NULL;
        // if (strcmp(path->args[0], "exit") == 0) // Exit shell if "exit" command is entered
        //     exit(0);

            // // Fork a child process to execute external commands
            // pid_t pid = fork();
            // if (pid == -1) {
            //     perror("fork");
            //     exit(1);
            // } else if (pid == 0) {
            //     // Child process
            //     if (execvp(args[0], args) == -1) {
            //         perror("execvp");
            //         exit(1);
            //     }
            // } else {
            //     // Parent process
            //     if (waitpid(pid, &status, 0) == -1) {
            //         perror("waitpid");
            //         exit(1);
            //     }
            // }
    }
    free_all(path);
    return (EXIT_SUCCESS);
}

void    set_zero(t_data *path)
{
    path->cmd[0] = '\0';
    path->env = NULL;
    path->args = NULL;
    path->token = NULL;
    path->status = 0;
}

void    free_all(t_data *path)
{   
    int i;

    i = 0;
    while (path->args[i])
        free(path->args[i++]);
    free(path->args);
    free(path->token);
    free(path);
}