/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:19:11 by kchatvet          #+#    #+#             */
/*   Updated: 2023/06/21 07:56:18 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void cmd_cd(t_andro shell_var)
{
    char *home_dir;
    
    home_dir = getenv("USER");
    if (home_dir != NULL)
    {
        chdir(home_dir);
    }
}