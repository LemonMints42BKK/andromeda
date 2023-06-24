/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 10:15:40 by kchatvet          #+#    #+#             */
/*   Updated: 2023/06/24 14:37:44 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void echo_cmd(char **tokens)
{
        int i = 1;
        int new_line = 1;

        if (tokens[i] != NULL && ft_strcmp(tokens[i], "-n") == 0) {
            new_line = 0;
            i++;
        }

        while (tokens[i] != NULL) 
        {
           if (tokens[i][0] == '\"' || tokens[i][0] == '\'')
            {    
                tokens[i][0] = 127;
            }
            if ( (tokens[i][ft_strlen(tokens[i])-1] == '\"'))
                 tokens[i][ft_strlen(tokens[i])-1]  = '\0';
             if ( (tokens[i][ft_strlen(tokens[i])-1] == '\''))
                 tokens[i][ft_strlen(tokens[i])-1]  = '\0';     
                
            printf("%s", tokens[i]);
            i++;
            if (tokens[i] != NULL) {
                printf(" ");
            }
        }

        if (new_line) {
            printf("\n");
        }
}
