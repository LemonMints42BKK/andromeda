/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   andro_fget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 05:27:18 by codespace         #+#    #+#             */
/*   Updated: 2023/05/06 12:10:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// char	*andro_fgets(char *buffer, int size, FILE *stream)
// {
// 	char	*prompt;

// 	prompt = readline ("Andromeda$ ");
// 	if (prompt != NULL)
// 	{
// 		ft_strlcpy(buffer, prompt, size);
// 		add_history(prompt);
// 	}
// 	free(prompt);
// 	if (stream != NULL)
// 	{
// 		ft_strlcpy(buffer, stream, size);
// 		add_history(stream);
// 	}


// 	return (buffer);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	src_len;
// 	size_t	i;

// 	src_len = ft_strlen(src);
// 	i = 0;
// 	if (dstsize)
// 	{
// 		while ((i < (dstsize - 1)) && (src[i] != '\0'))
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	return (src_len);
// }

char *myfgets(char *str, int n, FILE *stream) {
    int c;
    char *p = str;

    /* Make sure we have a valid FILE pointer */
    if (stream == NULL) {
        return NULL;
    }

    /* Read up to n-1 characters from the stream */
    while (--n > 0 && (c = getc(stream)) != EOF) {
        *p++ = (char) c;

        /* If we encounter a newline character, stop reading */
        if (c == '\n') {
            break;
        }
    }

    /* Terminate the string with a null character */
    *p = '\0';

    /* If no characters were read, return NULL */
    if (p == str) {
        return NULL;
    }

    /* Otherwise, return the string */
    return str;
}

int	main(void)
{
	char flname[100];
	char *name;
	while(1)
	{
		printf("Enter your name: ");
		name = myfgets(flname, sizeof(flname), stdin);
		printf("Hello %s", name);
	}
	return (0);
}
