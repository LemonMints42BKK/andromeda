#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*myfgets(char *buffer, int size, FILE *stream)
{
	char	*prompt;

	prompt = readline ("Andromeda$ ");
	if (prompt != NULL)
	{
		ft_strlcpy(buffer, prompt, size);
	// 	add_history(prompt);
	}
	// free(prompt);
	// if (stream != NULL)
	// {
	// 	ft_strlcpy(buffer, stream, size);
	// 	add_history(stream);
	// }
	return (buffer);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize)
	{
		while ((i < (dstsize - 1)) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

int main()
{
	char *line;
	while (1)
	{
		line = myfgets(line, 1024, stdin);
		printf("%s", line);
	}
	return 0;
}
