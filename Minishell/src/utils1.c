/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 08:35:17 by kchatvet          #+#    #+#             */
/*   Updated: 2023/06/26 06:36:19 by kchatvet         ###   ########.fr       */
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

char* ft_strtok(char* str, const char* delim) 
{
    static char* nextToken = NULL; // Stores the pointer to the next token
    if (str != NULL) {
        nextToken = str;
    }

    if (nextToken == NULL) {
        return NULL; // No more tokens to extract
    }

    // Find the start of the token
    char* start = nextToken;
    while (*start != '\0' && ft_strchr(delim, *start) != NULL) {
        start++;
    }

    if (*start == '\0') {
        nextToken = NULL; // No more tokens to extract
        return NULL;
    }

    // Find the end of the token
    char* end = start;
    while (*end != '\0' && strchr(delim, *end) == NULL) {
        end++;
    }

    if (*end != '\0') {
        *end = '\0'; // Replace the delimiter with null terminator
        nextToken = end + 1; // Set the pointer to the next token
    } else {
        nextToken = NULL; // No more tokens to extract
    }

    return start;
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


