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

# include "./libft/libft.h"
# include <limits.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>


# define ABC 555

# define MAX_CMD_LENGTH 100


typedef struct s_node
{
	char				cmd[MAX_CMD_LENGTH];
	char		*args[MAX_CMD_LENGTH];
	char		*token;
	int				status;
	int				arg_index;
	struct s_node	*next;
}	t_node;

typedef struct s_matrix
{
	struct s_node	**rows;
	int				rows_count;
	int				cols_count;
}	t_mat;

typedef struct s_mini
{
	void	*nameA;
	char	*nameB;
	int		col;
	int		row;
	int		a;
	int		b;
	int		c;
	char	**argv;
	t_mat	*mat;
}	t_mini;

void	init_mini(t_mini *mini);
void	error_check(int argc, char **argv);
void	read_map(char **argv, t_mini *mini);
void	read_map_matrix(char **argv, t_mini *mini, t_mat *mat);
void	free_array(char **tab);
void	init_data(int col, int row, char *str, t_mat *map);
void	create_matrix(t_mat *mat, int n, int m);
void	destroy_matrix(t_mat *mat);
void	add_to_matrix(t_mat *mat, t_mini mini);
void	value_from_matrix(t_mat *mat, t_mini *mini, int col, int row);
void	print_matrix(t_mat *mat, t_mini *mini);
void	xprint_matrix(t_mini *mini);
void	mini_free(t_mini *mini);


#endif
