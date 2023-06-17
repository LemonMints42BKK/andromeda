/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g65420029 <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:37:12 by g65420029         #+#    #+#             */
/*   Updated: 2023/06/05 11:37:29 by g65420029        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*myfgets(char *buffer, int size, FILE *stream)
{
	char	*line;
    int     c;

    line = buffer;
    if (stream == NULL)
        return(NULL);
    if (stream->_fileno == 0)
        line = readline ("Andromeda$ ");
	if (line && (ft_strncmp(line, "", 1) != 0))
	{
		ft_strlcpy(buffer, line, size);
        add_history(line);
        andro_wr_history(line);
	}
    if (stream->_fileno == 0)
	    free(line);
	return (buffer);
}


