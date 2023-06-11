/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:37:12 by g65420029         #+#    #+#             */
/*   Updated: 2023/06/11 10:15:01 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

#define HISTORY_FILE ".andro_history"


/*
static void   my_read_history(void)
{
    int fd;
    char *ch;
    int     buffer_size;

    buffer_size = BUFFER_SIZE;
    printf("B S = %d\n",buffer_size);
    
    fd = open(HISTORY_FILE, O_RDWR);
    if (fd == -1)
    {
        printf("Error : history file\n");
        return ;
    }
    ch = get_next_line(fd);
    printf("\n%s\n",ch);
    add_history(ch);
    while (ch)
    {
        ch++;
         add_history(ch);
        ch = get_next_line(fd);
   
  }
    close (fd);
    
    
}
*/


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


