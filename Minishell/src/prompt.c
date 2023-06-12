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

#define HISTORY_FILE ".andro_history"

static void   my_write_history(char *line)
{
    int fd;

    fd = open(HISTORY_FILE, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1)
        ft_putstr_fd("Error : To open history file\n", 2);
    write(fd, "\n", 1);
    if (close(fd) == -1)
        ft_putstr_fd("Error : To close history file\n", 2);    
}

int mygetc(FILE *stream)
{
    unsigned char   c;
    if (stream == NULL)
        return(EOF);
    return (c);
}

char	*myfgets(char *buffer, int size, FILE *stream)
{
	char	*line;
    int     c;

    line = buffer;
    if (stream == NULL)
        return(NULL);
    if (stream->_fileno == 0)
        line = readline ("Andromeda$ ");
    else if (stream->_fileno > 0)
    {
        c = mygetc(stream);
        while (--size > 0 && c != '\0')
        {
            *line++ = (char) c;
            if (c == '\n')
                break;
            c = mygetc(stream);
        }
        *line = '\0';
    }
	if (line && (ft_strncmp(line, "", 1) != 0))
	{
		ft_strlcpy(buffer, line, size);
        add_history(line);
        my_write_history(line);
	}
    if (stream->_fileno == 0)
	    free(line);
	return (buffer);
}


