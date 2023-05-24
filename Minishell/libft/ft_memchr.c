/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:58:06 by kchatvet          #+#    #+#             */
/*   Updated: 2022/03/06 00:03:33 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*dest;
	size_t					i;

	dest = s;
	i = 0;
	while (i < n)
	{
		if (dest[i] == (unsigned char)c)
			return ((void *)&dest[i]);
		i++;
	}
	return (0);
}
