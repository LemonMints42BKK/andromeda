/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:46:53 by kchatvet          #+#    #+#             */
/*   Updated: 2022/03/20 11:17:03 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	return (start);
}

static size_t	find_stop(char const *s1, char const *set)
{
	size_t	stop;

	stop = ft_strlen(s1);
	while (ft_strchr(set, s1[stop]) && stop)
		stop--;
	return (stop);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	stop;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = find_start(s1, set);
	stop = find_stop(s1, set) + 1;
	i = 0;
	if (stop != 0 && start < stop && *s1)
	{
		str = malloc(sizeof(char) * ((stop - start) + 1));
		if (!str)
			return (NULL);
		while (start < stop)
			str[i++] = s1[start++];
		str[i] = '\0';
		return (str);
	}
	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}
