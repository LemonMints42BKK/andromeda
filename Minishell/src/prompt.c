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

// static void   andro_wr_history(char *line)
// {
//     int fd;

//     fd = open(HISTORY_FILE, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
//     if (fd == -1)
//         ft_putstr_fd("Error : To open history file\n", 2);
//     write(fd, "\n", 1);
//     if (close(fd) == -1)
//         ft_putstr_fd("Error : To close history file\n", 2);    
// }

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


