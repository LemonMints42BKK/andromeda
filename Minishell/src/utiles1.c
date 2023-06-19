/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 08:35:17 by kchatvet          #+#    #+#             */
/*   Updated: 2023/06/19 16:11:06 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t  ft_strcspn(const char *s, const char *reject)
{
        size_t  i = 0;
        size_t  j = 0;

        while(s[i])
        {
                j = 0;
                while(reject[j])
                {
                        if(s[i] == reject[j])
                                return(i);
                        j++;
                }
                i++;
        }
        return (i);
}

void clean_exit(int code_error)
{
        printf("\n bye\n");
        rl_clear_history();
        exit(code_error);
}

