/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 22:30:32 by kchatvet          #+#    #+#             */
/*   Updated: 2022/03/20 14:46:05 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	next_pos(char const *s, char c)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0' && s[index] != c)
		index++;
	return (index);
}

static size_t	size_sp(char const *s, char c)
{
	char	*ch;
	size_t	size;

	ch = (char *)s;
	size = 0;
	while (*ch != '\0')
	{
		while (*ch != '\0' && *ch != c)
			ch++;
		while (*ch != '\0' && *ch == c)
			ch++;
		size++;
	}
	return (size);
}

static void	ch_split(char **array, const char *s, char c)
{
	char	*ch;
	size_t	index;
	size_t	j;
	size_t	k;

	ch = (char *)s;
	index = next_pos(ch, c);
	k = 0;
	while (index)
	{
		array[k] = malloc(sizeof(char) * (index + 1));
		j = 0;
		while (j < index)
			array[k][j++] = *(ch++);
		array[k][j] = '\0';
		k++;
		while (*ch != '\0' && *ch == c)
			ch++;
		index = next_pos(ch, c);
	}
	array[k] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	while (*s != '\0' && *s == c)
		s++;
	array = malloc(sizeof(char *) * (size_sp(s, c) + 1));
	if (!array)
		return (NULL);
	ch_split(array, s, c);
	if (!array)
		free(array);
	return (array);
}
