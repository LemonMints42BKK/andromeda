/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:46:46 by kchatvet          #+#    #+#             */
/*   Updated: 2022/09/16 14:44:41 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sub_left_digit(t_record *record, char *str, char *padded)
{
	int	len;
	int	space;
	int	prefix;
	int	n;

	len = 0;
	prefix = 0;
	n = record->signdi;
	space = 0;
	while (space++ < (record->preci - (int)ft_strlen(str)))
		len += write(1, "0", 1);
	len += write(1, str, ft_strlen(str));
	prefix = space - 1;
	if (record->width < record->preci)
		len += write(1, str, ft_strlen(str));
	space = 0;
	while (space++ < (record->width - (int)ft_strlen(str) - prefix - n))
		len += write(1, padded, 1);
	return (len);
}

int	left_digit(t_record *record, char *str, char *padded)
{
	int	len;
	int	n;

	len = 0;
	n = record->signdi;
	if (n)
		len += write(1, "-", 1);
	if (record->width >= record->preci)
		len += sub_left_digit(record, str, padded);
	if (record->width < record->preci)
		len = loop_pad(len, (record->preci - (int)ft_strlen(str)), padded);
	return (len);
}

int	sub_right_digit(t_record *record, char *str, char *padded)
{
	int	n;
	int	len;

	len = 0;
	n = record->signdi;
	if ((record->width >= record->preci) && (!record->point))
		len = loop_pad(len, record->width - (int)ft_strlen(str) - n, padded);
	else
	{
		if (record->preci < (int)ft_strlen(str))
			record->preci = (int)ft_strlen(str);
		len = loop_pad(len, record->width - record->preci - n, padded);
	}
	return (len);
}

int	right_digit(t_record *record, char *str, char *padded)
{
	int	len;
	int	n;

	len = 0;
	n = record->signdi;
	if (n && record->zero)
		len += write(1, "-", 1);
	len += sub_right_digit(record, str, padded);
	if (n && !record->zero)
		len += write(1, "-", 1);
	if (record->width < record->preci)
		len = loop_pad(len, record->preci - (int)ft_strlen(str), padded);
	if ((record->point) && (record->width >= record->preci))
	{
		len = loop_pad(len, record->preci - (int)ft_strlen(str), "0");
		len += write(1, str, ft_strlen(str));
	}
	else
		len += write(1, str, ft_strlen(str));
	return (len);
}

int	loop_pad(int len, int n_loop, char *padded)
{
	int	space;

	space = 0;
	while (space++ < n_loop)
		len += write(1, padded, 1);
	return (len);
}
