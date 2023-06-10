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
    {
        printf("Error : history file\n");
        return ;
    }
    ft_putstr_fd(line, fd);
    write(fd, "\n", 1);

    if (close(fd) == -1)
    {
         printf("Error : close history file\n");
        return ;
    }
}

char	*myfgets(char *buffer, int size, FILE *stream)
{
	char	*line;

//	read_history(HISTORY_FILE);//
	line = readline ("Andromeda$ ");
	if (line && *line)
	{
		ft_strlcpy(buffer, line, size);
      //  rl_clear_history();
        add_history(line);
  	  // write_history(HISTORY_FILE);//
        my_write_history(line);
      //  rl_replace_line(line, 1);
       // rl_redisplay();
	}
	free(line);
	// if (stream != NULL)
	// {
	// 	ft_strlcpy(buffer, stream, size);
	// 	add_history(stream);
	// }
	return (buffer);
}


