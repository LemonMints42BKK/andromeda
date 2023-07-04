    #include "../minishell.h"
    

    void    andro_env(t_envlist *env)
    {
        t_envlist *ptr;

        ptr = env;
        while (ptr != NULL)
        {
            printf ("%s=%s", ptr->key, ptr->value);
            ptr = ptr->next;
        }
    }
