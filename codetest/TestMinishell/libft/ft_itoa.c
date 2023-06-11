/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:28:44 by kchatvet          #+#    #+#             */
/*   Updated: 2022/03/19 07:32:48 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*int_char_p(char *s, int nb, int nbr)
{
	while (nbr)
	{
		s[nbr - 1] = 48 + nb % 10;
		nb /= 10;
		nbr--;
	}
	return (s);
}

static char	*int_char_n(char *s, int nb, int nbr)
{
	while (nbr > 0)
	{
		s[nbr - 1] = 48 - nb % 10;
		nb /= 10;
		nbr--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	l;
	int		nbr;

	l = 10;
	nbr = 1;
	while (n / l)
	{
		l *= 10;
		nbr++;
	}
	if (n < 0)
		nbr++;
	str = malloc(sizeof(char) * (nbr + 1));
	if (!str)
		return (NULL);
	str[nbr] = '\0';
	if (n >= 0)
		str = int_char_p(str, n, nbr);
	else
	{
		str = int_char_n(str, n, nbr);
		str[0] = '-';
	}
	return (str);
}
