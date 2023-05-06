/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:35:05 by kchatvet          #+#    #+#             */
/*   Updated: 2022/03/09 21:30:32 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strj;

	if (!s1 || !s2)
		return (NULL);
	else
		strj = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!strj)
		return (NULL);
	ft_memcpy (strj, s1, ft_strlen(s1));
	ft_memcpy ((strj + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
	return (strj);
}
