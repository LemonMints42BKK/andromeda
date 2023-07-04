/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:37:12 by g65420029         #+#    #+#             */
/*   Updated: 2023/07/04 08:27:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char    *myfgets(char *buffer, int size, FILE *stream, int status)
{
	char	*line;

    line = buffer;
    if  (stream == NULL)
        return(NULL);
    if (stream->_fileno == 0)
    {
        if (status != 2 )
		     line = readline ("\033[0;92mAn\033[0;33mdro\033[0;91mme\033[0;95mda\033[0;34m$\033[0m ");
        else
             line = readline ("");
    }
    if (line == NULL)
    {
        write (1, "exit\n", 5);
        free (line);
        exit(errno);
    }
    if (line && (ft_strncmp(line, "", 1) != 0))
	{
		ft_strlcpy(buffer, line, size);
        add_history(line); 
        andro_wr_history(line);
	}
    else if (status == 2 )
        write(1, "\n", 1);
    status = 0;
    free(line);
	return (buffer);
}




