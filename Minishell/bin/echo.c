/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 10:15:40 by kchatvet          #+#    #+#             */
/*   Updated: 2023/06/24 10:17:00 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void echo_cmd(char **tokens)
{
        int i = 1;
        int new_line = 1;

        if (tokens[i] != NULL && strcmp(tokens[i], "-n") == 0) {
            new_line = 0;
            i++;
        }

        while (tokens[i] != NULL) 
        {
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
