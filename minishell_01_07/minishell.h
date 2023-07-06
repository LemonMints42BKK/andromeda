/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:33:00 by pnopjira          #+#    #+#             */
/*   Updated: 2023/07/06 02:32:02 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>

# define MAX_COMMAND_LENGTH 1024
# define MAX_CMD_LENGTH 100
# define MAX_ARGS 64
# define HISTORY_FILE ".andro_history"
# define NEWLINE '\n'
# define GREAT '>'
# define LESS '<'
# define GREATGREAT ">>"
# define LESSLESS "<<"
# define PIPE '|'
# define AMPERAND '&'
# define SINGLEQUOTE '\''
# define DOUBLEQUOTE '\"'
# define DOLLARSIGN '$'

typedef struct s_envlist
{
    char                *key;
    char                *value;
    struct s_envlist   *prev;
    struct s_envlist   *next;
}   t_envlist;

typedef struct s_simple_com
{
    int     n_args;
    char    ***args;//[row][colume][str of arg]
    char    **in_f;//[index][str]
    char    **out_f;
    char    **err_f;
    char    **append;
    char    **heredoc;    
}   t_simple_com; //  cmd_tb valueable

typedef struct s_command
{
    int                 n_simple_cmd;
    /*pipe list*/
    t_simple_com        *sim_commands;//[&cmd_tb]
    /*io_modifier_list*/
    char    **in_a;//[index][str of modifier]
    char    **out_a;
    char    **err_a;
    char    **app_a;
    char    **here_a;   
    struct s_command    *perv;
    struct s_command    *next;
}   t_command; //final_tb valueable

typedef struct s_andro
{
    pid_t           pid;
    char			cmd[MAX_COMMAND_LENGTH];
	t_envlist		*envlist;
	t_command	    *final_tb;
	int				status;
}   t_andro;

/*prompt*/
char		*myfgets(char *str, int n, FILE *stream, int status);
/*history*/
void		andro_wr_history(char *line);
void		andro_rd_history(void);
/*environment*/
void		get_env(t_envlist **envlist, char **envp);
t_envlist  *init_env(int envc, char **envp);
int			count_env(char **envp);
void		push(t_envlist **head, char **key, char **value);
void		pop(t_envlist **head, char *key);
/*signal*/
void	    enable_signals(void);
/*tokenize*/
t_command    *tokenize(char  *cmd);
/*Build in*/
void        cmd_cd(t_andro shell_var);

/*exe builtins cmd*/
int         exe_builtin_cmd(char **tokens, t_andro *data);
void        echo_cmd(char **tokens);
void        change_directory(char **tokens);
void        cmd_pwd(void);
void        cmd_env(char **env); 
// void        andro_env(t_envlist *env);
/*exit*/
void        free_t_simple_com(t_simple_com *temp);
void        free_t_command(t_command *temp);
void		free_t_envlist(t_envlist *temp);
void        clean_exit(int code_error, t_andro *data);
/*utils*/
size_t      ft_strcspn(const char *s, const char *reject);
int         ft_strcmp(char *s1, char *s2);
char        *ft_strtok(char* str, const char* delim);
void        free_tab(char **tab);
void        stack_destroy(t_envlist *stack);

/*print*/
void	    print_env(t_andro *data);
void	    print_final_tb(t_andro *data);
/*tokenize*/
// int     andro_parsing(t_data *path);
// //char    *strtok(char *str, char *delim);
// /*builtins*/
// void execute_command(char** args);
// void execute_external_command(char** args);
// void handle_redirections(char** args);
// void handle_pipes(char** args);
// void expand_environment_variables(char** args);
// void handle_cd_command(char** args);
// void handle_echo_command(char** args);
// void handle_pwd_command();
// void handle_export_command(char** args);
// void handle_unset_command(char** args);
// void handle_env_command();

#endif
