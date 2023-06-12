#include "utiles.h"

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
        {
            valid_str = 1;
            break;
        }
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
        printf("j = %d\n", j);
        printf("len = %d\n", len-j);
        *name = (char*)malloc(sizeof(char) * (j + 1));
        *var = (char*)malloc(sizeof(char) * (len - j));
        ft_strlcpy(*name, str, (j + 1));
        ft_strlcpy(*var, str+(j + 1), len - j);
    }
}

t_list  *init_env(int argc, char **argv)
{
    t_list  *head;
    char    *name;
    char    *var;
    int     i;

    i = 1;
    head = NULL;
    while(i < argc)
    {
        name_and_var(argv[i], &name, &var);
        if (name)
        { 
            push(&head, &name, &var);
        }
        i++;
    }
    return(head);
}
