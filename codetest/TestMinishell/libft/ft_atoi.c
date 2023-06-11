/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:43:29 by kchatvet          #+#    #+#             */
/*   Updated: 2022/03/06 14:43:28 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_spacex(int c)
{
	int	a;
	int	b;
	int	d;

	a = (c == ' ' || c == '\t' || c == '\n');
	b = (c == '\v' || c == '\f' || c == '\r');
	d = (c < 33);
	return (a || b || d);
}

int	ft_atoi(const char *str)
{
	unsigned long int	ans;
	size_t				i;
	int					minus;

	i = 0;
	minus = 1;
	ans = 0;
	if (*str == '\0' || *str == '\e')
		return (0);
	while (is_spacex(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			minus *= -1;
	while (ft_isdigit(str[i]))
	{
		ans *= 10;
		ans += str[i] - '0';
		i++;
	}
	return (ans * minus);
}
