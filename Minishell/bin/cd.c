/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:19:11 by kchatvet          #+#    #+#             */
/*   Updated: 2023/06/22 02:56:10 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int change_directory(const char *path) {
    if (chdir(path) != 0) {
        perror("cd");
        return 1;
    }
    
    return 0;
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