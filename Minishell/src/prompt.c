/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 05:27:18 by codespace         #+#    #+#             */
/*   Updated: 2023/05/06 12:10:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#define HISTORY_FILE ".andro_history"

static void   my_write_history(char *line)
{
    int fd;

    fd = open(HISTORY_FILE, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    printf("%d \n",fd);
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


