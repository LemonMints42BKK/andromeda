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

char	*myfgets(char *buffer, int size, FILE *stream)
{
	char	*line;

	read_history(HISTORY_FILE);//
	line = readline ("Andromeda$ ");
	if (line && *line)
	{
		ft_strlcpy(buffer, line, size);
		add_history(line);
		write_history(HISTORY_FILE);//
	}
	free(line);
	// if (stream != NULL)
	// {
	// 	ft_strlcpy(buffer, stream, size);
	// 	add_history(stream);
	// }
	return (buffer);
}

// char    *myfgets(char *str, int n, FILE *stream)
// {
//     int c;
//     char *p = str;

//     /* Make sure we have a valid FILE pointer */
//     if (stream == NULL) {
//         return NULL;
//     }

//     /* Read up to n-1 characters from the stream */
//     while (--n > 0 && (c = getc(stream)) != EOF) {
//         *p++ = (char) c;

//         /* If we encounter a newline character, stop reading */
//         if (c == '\n') {
//             break;
//         }
//     }

//     /* Terminate the string with a null character */
//     *p = '\0';

//     /* If no characters were read, return NULL */
//     if (p == str) {
//         return NULL;
//     }

//     /* Otherwise, return the string */
//     return str;
// }
