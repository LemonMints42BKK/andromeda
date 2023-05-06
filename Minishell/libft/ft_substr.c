/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:50:20 by kchatvet          #+#    #+#             */
/*   Updated: 2022/03/20 12:03:26 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	s_length(char const *s, unsigned int start, size_t len)
{
	if (ft_strlen(s) > (start + len))
		return (len + 1);
	return (ft_strlen(s) - start + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_st;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		sub_st = malloc(sizeof(char) * s_length(s, start, len));
		if (!sub_st)
			return (NULL);
		while (i < len && s[start + i])
		{
			sub_st[i] = s[start + i];
			i++;
		}
	}
	else
		sub_st = malloc(sizeof(char));
	if (!sub_st)
		return (NULL);
	sub_st[i] = '\0';
	return (sub_st);
}
