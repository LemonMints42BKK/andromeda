/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 08:35:17 by kchatvet          #+#    #+#             */
/*   Updated: 2023/06/21 07:04:47 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t  ft_strcspn(const char *s, const char *reject)
{
        size_t  i = 0;
        size_t  j = 0;

        while(s[i])
        {
                j = 0;
                while(reject[j])
                {
                        if(s[i] == reject[j])
                                return(i);
                        j++;
                }
                i++;
        }
        return (i);
}

int    ft_strcmp(char *s1, char *s2)
{
        int     i = 0;

        while (s1[i] && s2[i] && (s1[i] == s2[i]))
                i++;
        return (s1[i] - s2[i]);
}

void    free_array(char **tab)
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

void    stack_destroy(t_envlist *stack)
{
        t_envlist  *node;
        t_envlist  *next;

        node = stack->prev;
        while (node)
        {
                next = node->prev;
                free(node);
                node = next;
        }
        
        node = stack->prev;
        while (node)
        {
                next = node->next;
                free(node);
                node = next;
        }
        
        free(stack);
}


