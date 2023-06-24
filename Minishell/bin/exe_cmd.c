/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 10:04:51 by kchatvet          #+#    #+#             */
/*   Updated: 2023/06/24 12:14:28 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int exe_builtin_cmd(char **tokens)
{
   if (ft_strcmp(tokens[0], "echo") == 0)
   {
       echo_cmd(tokens);
   }
   else if (ft_strcmp(tokens[0], "cd") == 0)
   {
       change_directory(tokens);
   }
   else if (ft_strcmp(tokens[0], "pwd") == 0)
   {
        cmd_pwd();
   }
   else if (ft_strcmp(tokens[0], "./minishell") == 0)
    {
        execve("./", tokens, NULL);
    }   
   else
     return (42);
     
   return (0);   
    
}