/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:47:14 by kchatvet          #+#    #+#             */
/*   Updated: 2022/07/14 13:43:24 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	lenstr(const char *s)
{
	size_t	ct;

	ct = 0;
	while (s[ct] != '\0')
	{
		ct++;
	}
	return (ct);
}

void	*copymem(void *dst, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	s = src;
	d = dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*joinstr(char *s1, char const *s2)
{
	char	*strj;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	else
		strj = malloc((lenstr(s1) + lenstr(s2) + 1) * sizeof(char));
	if (!strj)
		return (NULL);
	copymem(strj, s1, lenstr(s1));
	copymem((strj + lenstr(s1)), s2, lenstr(s2) + 1);
	free(s1);
	return (strj);
}
