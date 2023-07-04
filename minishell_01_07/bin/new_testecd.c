#include "../minishell.h"

void change_directory(char **tokens) 
{
    char *home_dir;
    char *str;
    
     str = getenv("HOME");
    home_dir =ft_strtrim(str, " =");
    free (str);
    
    printf("home dir %s = \n",home_dir);
    if (tokens[1] == NULL) 
    {    
            if (home_dir != NULL) 
            {
                chdir(home_dir);
            }
        } 
        else 
        {
            printf("dir to change %s", tokens[1] );
            if (chdir(tokens[1]) != 0) 
            {
                perror("cd failed");
            }
        }
}
 int main(int argc, char **argv, char **env)
 {
   

    (void)argc;



   change_directory(argv);
 }