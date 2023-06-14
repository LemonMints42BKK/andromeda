/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:26:05 by kchatvet          #+#    #+#             */
/*   Updated: 2023/05/06 12:15:39 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_CMD_LENGTH 100
#define MAX_ARGS 64
#define HISTORY_FILE ".andro_history"

/*prompt*/
char            *myfgets(char *str, int n, FILE *stream);
void execute_command(char** args);
void execute_external_command(char** args);
void handle_redirections(char** args);
void handle_pipes(char** args);
void expand_environment_variables(char** args);
void handle_cd_command(char** args);
void handle_echo_command(char** args);
void handle_pwd_command();
void handle_export_command(char** args);
void handle_unset_command(char** args);
void handle_env_command();

#endif
