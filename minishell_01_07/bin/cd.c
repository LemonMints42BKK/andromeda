/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:19:11 by kchatvet          #+#    #+#             */
/*   Updated: 2023/07/06 02:36:56 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void change_directory(char **tokens) 
{
    char *home_dir;
    char *str;
    
    str = getenv("HOME");
    home_dir =ft_strtrim(str, "=");
    //  printf("home dir %s=x\n",home_dir);
    if (tokens[1] == NULL) 
    {    
            if (home_dir != NULL) 
            {
                chdir(home_dir);
            }
        } 
        else 
        {
     //       printf("dir to change %s", tokens[1] );
            if (chdir(tokens[1]) != 0) 
            {
                perror("cd failed");
            }
        }
    free(home_dir);
}


/*
void cmd_cd(t_andro shell_var)
{
    char *home_dir;
    
    home_dir = getenv("USER");
    if (home_dir != NULL)
    {
        chdir(home_dir);
    }
}
*/