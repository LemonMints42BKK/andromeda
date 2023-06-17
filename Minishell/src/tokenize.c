#include "../minishell.h"
#include "utiles.h"

int andro_parsing(t_data *path)
{
    int arg_index;

    arg_index = 0;
    path->args = (t_list **)malloc(sizeof(t_list *) * MAX_ARGS);
    path->token = strtok(path->cmd, " "); //Tokenize input into arguments
    while (path->token != NULL)
    {
        path->args[arg_index++] = path->token;
        path->token = strtok(NULL, " ");
    }
    path->args[arg_index] = NULL;
    return (EXIT_SUCCESS);
}

char    *strtok(char *str, char *delim)
{
    static char *s;
    char *ret;
    int i;

    if (str != NULL)
        s = str;
    if (s == NULL)
        return (NULL);
    ret = (char *)malloc(sizeof(char) * strlen(s));
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == *delim)
        {
            ret[i] = '\0';
            s = &s[i + 1];
            return (ret);
        }
        ret[i] = s[i];
        i++;
    }
    ret[i] = '\0';
    s = NULL;
    return (ret);
}