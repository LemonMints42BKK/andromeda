/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_getenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:09:24 by pnopjira          #+#    #+#             */
/*   Updated: 2023/06/18 07:44:00 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	get_env(t_envlist **envlist, char **envp)
{
	int		envc;

	envc = count_env(envp);
	*envlist = init_env(envc, envp);
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
