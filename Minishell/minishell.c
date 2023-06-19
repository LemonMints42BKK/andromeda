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
#include "./src/utiles.h"

int	main(int argc, char **argv, char **envp)
{
	char			cmd[MAX_COMMAND_LENGTH];
	t_envlist		*envlist;
	t_simple_com	*sim_cmd;

	get_env(&envlist, envp);
	if (envlist == NULL)
		return (EXIT_FAILURE);
	enable_signals();
	andro_rd_history();
	while (1)
	{
		if (!myfgets(cmd, MAX_CMD_LENGTH, stdin))
			return (perror("Error"), EXIT_FAILURE);
		if (ft_strchr(cmd, '\n'))
			*ft_strchr(cmd, '\n') = '\0';
		if (strcmp(sim_cmd->args[0], "exit") == 0)
			exit(0);
	}

// Fork a child process to execute external commands
		// pid_t pid = fork();
		// if (pid == -1) {
		//     perror("fork");
		//     exit(1);
		// } else if (pid == 0) {
		// Child process
		//     if (execvp(args[0], args) == -1) {
		//         perror("execvp");
		//         exit(1);
		//     }
		// } else {
		// Parent process
		//     if (waitpid(pid, &status, 0) == -1) {
		//         perror("waitpid");
		//         exit(1);
		//     }
		// }

		// Fork a child process to execute external commands
		// pid_t pid = fork();
		// if (pid == -1) {
		//     perror("fork");
		//     exit(1);
		// } else if (pid == 0) {
		// Child process
		//     if (execvp(args[0], args) == -1) {
		//         perror("execvp");
		//         exit(1);
		//     }
		// } else {
		// Parent process
		//     if (waitpid(pid, &status, 0) == -1) {
		//         perror("waitpid");
		//         exit(1);
		//     }
		// }
	while (envlist)
	{
		free_t_envlist(&envlist);
		envlist = envlist->next;
	}
	return (EXIT_SUCCESS);
}
