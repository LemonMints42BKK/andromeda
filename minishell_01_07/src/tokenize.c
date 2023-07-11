/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:33:39 by pnopjira          #+#    #+#             */
/*   Updated: 2023/07/04 09:12:15 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    setup_tab(t_command **com_tab);

t_command    *tokenize(char  *cmd)
{
    t_command   *final_tb;
    char        **temp;
    
    final_tb =(t_command*)malloc(sizeof(t_command));
    if (!final_tb)
        return (NULL);
    setup_tab(&final_tb);
    andro_lexer(&final_tb, cmd);
    return (final_tb);
}

void    setup_tab(t_command **com_tab)
{
    (*com_tab)->n_simple_cmd = 0;
    (*com_tab)->sim_commands = NULL;
    (*com_tab)->in_a = NULL;
    (*com_tab)->out_a = NULL;
    (*com_tab)->err_a = NULL;
    (*com_tab)->app_a = NULL;
    (*com_tab)->here_a = NULL;
    (*com_tab)->perv = NULL;
    (*com_tab)->next = NULL;
}
// int andro_parsing(t_data *path)
// {
//     int arg_index;

//     arg_index = 0;
//     path->args = (t_list **)malloc(sizeof(t_list *) * MAX_ARGS);
//     path->token = strtok(path->cmd, " "); //Tokenize input into arguments
//     while (path->token != NULL)
//     {
//         path->args[arg_index++] = path->token;
//         path->token = strtok(NULL, " ");
//     }
//     path->args[arg_index] = NULL;
//     return (EXIT_SUCCESS);
// }

// char    *strtok(char *str, char *delim)
// {
//     static char *s;
//     char *ret;
//     int i;

//     if (str != NULL)
//         s = str;
//     if (s == NULL)
//         return (NULL);
//     ret = (char *)malloc(sizeof(char) * strlen(s));
//     i = 0;
//     while (s[i] != '\0')
//     {
//         if (s[i] == *delim)
//         {
//             ret[i] = '\0';
//             s = &s[i + 1];
//             return (ret);
//         }
//         ret[i] = s[i];
//         i++;
//     }
//     ret[i] = '\0';
//     s = NULL;
//     return (ret);
// }