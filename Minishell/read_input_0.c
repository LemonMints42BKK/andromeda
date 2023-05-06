/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:55:45 by kchatvet          #+#    #+#             */
/*   Updated: 2023/05/06 12:10:31 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_matrix(t_mat *mat, int n, int m)
{
	int	i;

	mat->rows_count = n;
	mat->cols_count = m;
	mat->rows = malloc(n * sizeof(t_mat *));
	i = 0;
	while (i < n)
	{
		mat->rows[i] = NULL;
		i++;
	}
}

void	destroy_matrix(t_mat *mat)
{
	int		i;
	t_node	*current;
	t_node	*temp;

	i = 0;
	while (i < mat->rows_count)
	{
		current = mat->rows[i];
		while (current != NULL)
		{
			temp = current;
			current = current->next;
			free(temp);
		}
		i++;
	}
	free(mat->rows);
	mat->rows = NULL;
	mat->rows_count = 0;
	mat->cols_count = 0;
}

static void	sub_add(t_mat *mat, t_node *current, t_mini mini, t_node *new_node)
{
	int		i;

	i = 0;
	if (current == NULL)
	{
		mat->rows[mini.row] = new_node;
		return ;
	}
	if (mini.col == 0)
	{
		new_node->next = current;
		mat->rows[mini.row] = new_node;
		return ;
	}		
	while (i < mini.col - 1 && current->next != NULL)
	{
		current = current->next;
		i++;
	}
	new_node->next = current->next;
	current->next = new_node;
}

void	add_to_matrix(t_mat *mat, t_mini mini)
{
	t_node	*new_node;
	t_node	*current;

	new_node = (t_node *) malloc(sizeof(t_node));
	new_node->cmd = mini.com;
	new_node->args = mini.args;
	new_node->token = mini.token;
	new_node->type = mini.type;
	new_node->next = NULL;
	current = mat->rows[mini.row];
	sub_add(mat, current, mini, new_node);
}

void	value_from_matrix(t_mat *mat, t_mini *mini, int col, int row)
{
	t_node	*current;
	int		i;

	i = 0;
	current = mat->rows[row];
	while (i < col && current != NULL)
	{
		current = current->next;
		i++;
	}
	mini->cmd = current->value;
	mini->args = current->args;
	mini->token = current->token;
	mini->type = current->type;
	mini->status = current->status
}
