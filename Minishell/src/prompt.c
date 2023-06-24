/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:37:12 by g65420029         #+#    #+#             */
/*   Updated: 2023/06/24 03:18:22 by g65420029        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*myfgets(char *buffer, int size, FILE *stream,int status)
{
	char	*line;
    int     c;
   
    
    line = buffer;
    if (stream == NULL)
        return(NULL);
    if (stream->_fileno == 0)
        if (status != 2 )
		line = readline ("\033[0;92mAn\033[0;33mdro\033[0;91mme\033[0;95mda\033[0;34m$\033[0m ");
	else
    {
		line = readline("");
      
      //  status = 0;
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


