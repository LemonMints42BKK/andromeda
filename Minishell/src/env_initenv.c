/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_initenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:55:56 by pnopjira          #+#    #+#             */
/*   Updated: 2023/06/17 15:44:28 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "utiles.h"

void    pop(t_envlist **head, char **key);
void    is_empty(t_envlist **head, char **key, char **value);

void  free_t_envlist(t_envlist **temp)
{
    free((*temp)->key);
    free((*temp)->value);
    free(*temp);
    (*temp) = NULL;
}

void    pop(t_envlist **head, char **key)
{
    t_envlist	*temp;
    t_envlist  *ptr1;

    if (*head == NULL)
        return ;
    temp = *head;
    while (temp->key != *key)
        temp = temp->next;
	if (temp->prev == NULL)
    {
        *head = temp->next;
        free_t_envlist(&temp);
    }
    else
    {
        ptr1 = temp->prev;
		if (temp->next == NULL)
			ptr1->next = NULL;
		else
        {
			ptr1->next = temp->next;
        	temp->next->prev = ptr1;
		}
        free_t_envlist(&temp);
        ptr1 = NULL;
    }
    if (*head)
        (*head)->prev = NULL;
}

void    push(t_envlist **head, char **key, char **value)
{
    t_envlist	*temp;

	temp = (t_envlist *)malloc(sizeof(t_envlist));
	if (!temp)
		temp = NULL;
    temp->key = *key;
    temp->value = *value;
	temp->prev = NULL;
	temp->next = NULL;
	if (*head != NULL)
	{
		temp->next = *head;
        (*head)->prev = temp;
	}
    *head = temp;
	temp = NULL;
}

int    check_valid(char *str, int *j)
{
    int valid_str;

    valid_str = 0;
    *j = 0;
    while (str[*j] != '\0')
    {
        if (str[*j] == '=')
            valid_str = 1;
        (*j)++;
    }
    return (valid_str);
}

void    key_and_value(char *str, char **key, char **value)
{
    int     j;
    int     len;

    j = 0;
    len = ft_strlen(str);
    printf("len = %d\n", len);
    if (check_valid(str, &j))
    {
        *key = (char*)malloc(sizeof(char) * j);
        if (!*key)
            return ;
        *value = (char*)malloc(sizeof(char) * (len - j + 1));
        if (!*value)
            return ;
        ft_strlcpy(*key, str, j);
        ft_strlcpy(*value, (str + j), (len - j + 1));
    }
}

t_envlist  *init_env(int envc, char **envp)
{
    t_envlist  *head;
    char    *key;
    char    *value;
    int     i;

    i = 0;
    head = NULL;
    while(i < envc)
    {
        key_and_value(envp[i], &key, &value);
        if (key || value)
        {
            push(&head, &key, &value);
        }
        i++;
    }
    return(head);
}
