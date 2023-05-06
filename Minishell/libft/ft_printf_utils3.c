/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 09:41:17 by kchatvet          #+#    #+#             */
/*   Updated: 2022/09/15 19:21:31 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*int_char_p_kx(char *s, long nb, long nbr)
{
	while (nbr)
	{
		s[nbr - 1] = 48 + nb % 10;
		nb /= 10;
		nbr--;
	}
	return (s);
}

static char	*int_char_n_kx(char *s, long nb, long nbr)
{
	while (nbr > 0)
	{
		s[nbr - 1] = 48 - nb % 10;
		nb /= 10;
		nbr--;
	}
	return (s);
}

char	*kx_itoa(long n)
{
	char			*str;
	unsigned long	l;
	long			nbr;

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
		str = int_char_p_kx(str, n, nbr);
	else
	{
		str = int_char_n_kx(str, n, nbr);
		str[0] = '-';
	}
	return (str);
}
