/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:03:37 by kchatvet          #+#    #+#             */
/*   Updated: 2023/07/07 08:38:22 by kchatvet         ###   ########.fr       */
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

static char	*sub_strtok(char *ptr, const char *delim, int se)
{
	char	*len;

	len = ptr;
        if (se)
	{
		while (*len != '\0' && ft_strchr(delim, *len) != NULL)
			len++;
	}
	else
	{
		while (*len != '\0' && ft_strchr(delim, *len) == NULL)
			len++;
	}
	return (len);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*next_token;
	char		*start;
	char		*end;

	if (str != NULL)
		next_token = str;
	if (next_token == NULL)
		return (NULL);
	start = sub_strtok(next_token, delim, 1);
	if (*start == '\0')
	{
		next_token = NULL;
		return (NULL);
	}
	end = sub_strtok(start, delim, 0);
	if (*end != '\0')
	{
		*end = '\0';
		next_token = end + 1;
	}
	else
		next_token = NULL;
	return (start);
}

/*
char	*ft_strtok(char *str, const char *delim)
{
	static char	*next_token;
	char	*start;
	char	*end;

	if (str != NULL)
		next_token = str;
	if (next_token == NULL)
		return (NULL);
	start = next_token;
	while (*start != '\0' && ft_strchr(delim, *start) != NULL)
		start++;
	if (*start == '\0')
	{
		next_token = NULL;
		return (NULL);
	}
	end = start;
	while (*end != '\0' && ft_strchr(delim, *end) == NULL)
		end++;
	if (*end != '\0')
	{
		*end = '\0';
		next_token = end + 1;
	}
	else
		next_token = NULL;
	return (start);
}
*/
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
