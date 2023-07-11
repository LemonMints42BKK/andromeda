/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:55:56 by pnopjira          #+#    #+#             */
/*   Updated: 2023/07/04 08:49:22 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void    pop(t_envlist **head, char *key);
int    is_empty(t_envlist **head);

int	is_empty(t_envlist **head)
{
	if (*head == NULL)
		return (1);
	else
		return (0);
}

void    pop(t_envlist **head, char *key)
{
    t_envlist	*temp;
    t_envlist  *ptr1;

    temp = *head;
    if (temp != NULL)
    {
        while (ft_strncmp(temp->key, key, ft_strlen(key)) != 0)
            temp = temp->next;
        if (temp == NULL)
            return ;
        if (temp->prev == NULL)
            *head = temp->next;
        else
        {
            if (temp->next == NULL)
                temp->prev->next = NULL;
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
        }
        free_t_envlist(temp);
        ptr1 = NULL;
    }
}

void    push(t_envlist **head, char **key, char **value)
{
    t_envlist	*temp;
    t_envlist	*ptr;

    ptr = *head;
	temp = (t_envlist *)malloc(sizeof(t_envlist));
	if (!temp)
		temp = NULL;
    temp->key = *key;
    temp->value = *value;
	temp->prev = NULL;
	temp->next = NULL;
    if (ptr != NULL)
    {
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
        temp->prev = ptr;
    }
    else
        *head = temp;
    ptr = NULL;
	temp = NULL;
}

int    check_valid(char *str, int *j)
{
    int valid_str;

    valid_str = 0;
    *j = 0;
    while (str[*j] != '\0')
    {
        (*j)++;
    if (str[*j] == '=')
    {
        valid_str = 1;
        break ;
    }
    }
    return (valid_str);
}

int    key_and_value(char *str, char **key, char **value)
{
    int     j;
    int     len;

    j = 0;
    len = ft_strlen(str);
    if (check_valid(str, &j))
    {
        *key = (char*)malloc(sizeof(char) * (j + 1));
        if (!*key)
            return (perror("error"), EXIT_FAILURE);
        *value = (char*)malloc(sizeof(char) * (len - j + 2));
        if (!*value)
            return (perror("error"), EXIT_FAILURE);
        ft_strlcpy(*key, str, j + 1);
        ft_strlcpy(*value, (str + j + 1), (len - j + 2));
    }
    return (EXIT_SUCCESS);
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
        if (key_and_value(envp[i], &key, &value))
            return (NULL);
        if (key || value)
        {
            push(&head, &key, &value);
        }
        i++;
    }
    return(head);
}
