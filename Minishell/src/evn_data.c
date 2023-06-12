#include "./minishell.h"
#include "utiles.h"
bool    check_valid(char *str, int *j)
{
    bool valid_str;

    valid_str = false;
    j = 0;
    while (str[j])
    {
        if (str[j] == '=')
        {
            valid_str = ture;
            break;
        }
        j++;
    }
    return (valid_str);
}

void    name_and_var(char *str, char **name, char **var)
{
    int     j;
    int     len;

    len = ft_strlen(str);
    if (check_valid(str, &j))
    {
        *name = (char*)malloc(sizeof(char) * j);
        *var = (char*)malloc(sizeof(char) * (len - j + 1));
        ft_strlcpy(name, str, j);
        ft_strlcpy(var, (str + j), (len - j + 1));
    }
}

t_list  *init_env(int argc, char **argv)
{
    t_list  head;
    char    *name;
    char    *var;
    int     i;

    i = 0;
    while(i < argc)
    {
        name_and_var(argv[i], &name, &var);
        if (name && var)
            push(&head, &name, &var);
        i++;
    }
}
