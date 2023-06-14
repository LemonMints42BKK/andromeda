/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:21:59 by kchatvet          #+#    #+#             */
/*   Updated: 2022/09/15 23:10:08 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*di_char_p(char *s, int nb, int nbr)
{
	while (nbr)
	{
		s[nbr - 1] = 48 + nb % 10;
		nb /= 10;
		nbr--;
	}
	return (s);
}

static char	*di_char_n(char *s, int nb, int nbr)
{
	while (nbr > 0)
	{
		s[nbr - 1] = 48 - nb % 10;
		nb /= 10;
		nbr--;
	}
	return (s);
}

char	*di_itoa(int n)
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
	str = malloc(sizeof(char) * (nbr + 1));
	if (!str)
		return (NULL);
	str[nbr] = '\0';
	if (n >= 0)
		str = di_char_p(str, n, nbr);
	else
	{
		str = di_char_n(str, n, nbr);
	}
	return (str);
}
