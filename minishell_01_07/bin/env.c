    #include "../minishell.h"
    
/*
   void cmd_env(char **env) 
{
    int i = 0;
  
    while (env[i] != NULL) 
    {
        printf("%s\n", env[i]);
        i++;
    }
    printf ("kanit kanit ENV \n");
 
}
*/ 
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
