/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_getenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:09:24 by pnopjira          #+#    #+#             */
/*   Updated: 2023/06/18 06:19:34 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "utiles.h"
#include <string.h>

void	get_env(t_envlist **envlist, char **envp)
{
	int		envc;
	// t_envlist	*temp;// show env_var list

	envc = count_env(envp);
	*envlist = init_env(envc, envp);
	// temp = *envlist;
	// while (temp)
	// {	printf("%s=%s\n", temp->key, temp->value);
	// 	temp = temp->next;}
	return ;
}

int	count_env(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}
