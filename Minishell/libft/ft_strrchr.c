/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:30:28 by kchatvet          #+#    #+#             */
/*   Updated: 2022/03/04 00:18:24 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			s_len;
	size_t			i;
	unsigned char	ch;	

	s_len = ft_strlen(s);
	ch = c;
	s = s + s_len;
	i = 0;
	while ((*s != ch) && (i < s_len))
	{
		i++;
		s--;
	}
	if (*s == ch)
		return ((char *)s);
	return (0);
}
