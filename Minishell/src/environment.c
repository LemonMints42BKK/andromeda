#include "utiles.h"
void    pop(t_list **head, char **name);
void    is_empty(t_list **head, char **name, char **var);

void  free_t_list(t_list **temp)
{
    free((*temp)->name);
    free((*temp)->var);
    free(*temp);
    (*temp) = NULL;
}

void    pop(t_list **head, char **name)
{
    t_list	*temp;
    t_list  *ptr1;

    if (*head == NULL)
        return ;
    temp = *head;
    while (temp->name != *name)
        temp = temp->next;
    if (temp->next == NULL)
    {
        ptr1 = temp->prev;
        ptr1->next = NULL;
        free_t_list(&temp);
        ptr1 = NULL;
    }
    else if (temp->prev == NULL)
    {
        *head = temp->next;
        free_t_list(&temp);
    }
    else
    {
        ptr1 = temp->prev;
        ptr1->next = temp->next;
        temp->next->prev = ptr1;
        free_t_list(&temp);
        ptr1 = NULL;
    }
    if (*head)
        (*head)->prev = NULL;
}

void    push(t_list **head, char **name, char **var)
{
    t_list	*temp;

	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		temp = NULL;
    temp->name = *name;
    temp->var = *var;
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

void    name_and_var(char *str, char **name, char **var)
{
    int     j;
    int     len;

    j = 0;
    len = ft_strlen(str);
    if (check_valid(str, &j))
    {
        *name = (char*)malloc(sizeof(char) * j);
        *var = (char*)malloc(sizeof(char) * (len - j + 1));
        ft_strlcpy(*name, str, j);
        ft_strlcpy(*var, (str + j), (len - j + 1));
    }
}

t_list  *init_env(int argc, char **args)
{
    t_list  *head;
    char    *name;
    char    *var;
    int     i;

    i = 0;
    head = NULL;
    while(i < argc)
    {
        name_and_var(args[i], &name, &var);
        if (name)
        { 
            push(&head, &name, &var);
        }
        i++;
    }
    return(head);
}