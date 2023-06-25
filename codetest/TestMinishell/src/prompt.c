/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:37:12 by g65420029         #+#    #+#             */
/*   Updated: 2023/06/25 01:13:50 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

#define HISTORY_FILE ".andro_history"

void   my_read_history(void)
{
   int  fd;
    char *ch;
    char *str;
   
    fd = open(HISTORY_FILE, O_RDWR | O_CREAT);
    if (fd == -1)
    {
        printf("Error : history file\n");
        return ;
    }
      while ((ch = get_next_line(fd)) != NULL)
      {
         str = ft_strtrim(ch, "\n");
         free (ch);
         add_history(str);
         free(str);
      }
      close(fd);
}

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


	line = readline ("Andromeda$ ");
     my_read_history();
	if (line && *line)
	{
		ft_strlcpy(buffer, line, size);
          	 
        my_write_history(line);
        add_history(line);
      //  read_history(HISTORY_FILE);
     
      
	}
	free(line);
	// if (stream != NULL)
	// {
	// 	ft_strlcpy(buffer, stream, size);
	// 	add_history(stream);
	// }
	return (buffer);
}


