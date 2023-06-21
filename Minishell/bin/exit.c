/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:04:53 by kchatvet          #+#    #+#             */
/*   Updated: 2023/06/21 07:32:23 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void clean_exit(int code_error, t_envlist *envlist)
{         
        while (envlist)
	{
		free_t_envlist(&envlist);
		envlist = envlist->next;
	}
    //    stack_destroy(envlist);  
        
        printf("\n bye\n");
        rl_clear_history();
        exit(code_error);
}
