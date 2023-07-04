/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:00:03 by kchatvet          #+#    #+#             */
/*   Updated: 2023/06/21 07:18:30 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void cmd_pwd(void)
{
    char c_pwd[256];
    if (getcwd(c_pwd, sizeof(c_pwd)) != NULL)
    {
        printf("%s\n", c_pwd);
    }
    else 
    {
        perror("Andromeda: pwd: ");
    }
}