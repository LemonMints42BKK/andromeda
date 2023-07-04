/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:04:53 by kchatvet          #+#    #+#             */
/*   Updated: 2023/07/02 19:28:29 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void clean_exit(int code_error, t_envlist *envlist)
// {         
//         while (envlist)
// 	{
// 		free_t_envlist(&envlist);
// 		envlist = envlist->next;
// 	}
//     //    stack_destroy(envlist);  
        
//         write(1,"exit\n", 5);
//         rl_clear_history();
//         exit(code_error);
// }

void    clean_exit(int code_error, t_andro *data)
{       
        t_envlist       *envlist;
	t_command       *final_tb;

        envlist = data->envlist;
        final_tb = data->final_tb;
        while (envlist)
	{
		free_t_envlist(envlist);
		envlist = envlist->next;
	}
        while (final_tb)
        {
                free_t_command(final_tb);
                final_tb = final_tb->next;
        }
    //    stack_destroy(envlist);
        free (data);
        write(1,"exit\n", 5);
        rl_clear_history();
        exit(code_error);
}

void  free_t_envlist(t_envlist *temp)
{
        if (!temp)
                return ;
        free(temp->key);
        free(temp->value);
        free(temp);
        (temp) = NULL;
}

void  free_t_command(t_command *temp)
{
        if (!temp)
                return ;
        free_t_simple_com(temp->sim_commands);
        free_tab(temp->in_a);
        free_tab(temp->out_a);
        free_tab(temp->err_a);
        free_tab(temp->app_a);
        free_tab(temp->here_a);
        free(temp);
        (temp) = NULL;
}

void  free_t_simple_com(t_simple_com *temp)
{
        int     i;

        i = 0;
        if (!temp)
                return ;
        while (temp->args[i])
        {
                free_tab(temp->args[i]);
                i++;
        }
        free_tab(temp->in_f);
        free_tab(temp->out_f);
        free_tab(temp->err_f);
        free_tab(temp->append);
        free_tab(temp->heredoc);
        free(temp);
        (temp) = NULL;
}

void    free_tab(char **tab)
{
        int     i;

        if (!tab)
                return ;
        i = 0;
        while (tab[i])
        {
                free(tab[i]);
                i++;
        }
        free(tab);
}