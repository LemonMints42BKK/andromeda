/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:48:30 by kchatvet          #+#    #+#             */
/*   Updated: 2022/09/16 13:49:52 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sub_type_di(t_record *record, int di, char *str)
{
	int	printed;

	printed = 0;
	if (record->plus && (di >= 0))
		printed = write(1, "+", 1);
	else if (record->space && (di >= 0))
		printed = write(1, " ", 1);
	ft_putnbr_fd(di, 1);
	printed += ft_strlen(str);
	if (di < 0)
		printed++;
	return (printed);
}

int	type_di(t_record *record)
{
	int				di;
	int				printed;
	char			*str;

	di = va_arg(record->args, int);
	if (record->hash)
		return (-1);
	if (di == 0 && record->preci == 0 && record->point && record->width == 0)
		return (0);
	str = di_itoa(di);
	if (di < 0)
		record->signdi = 1;
	if (!record->plus && !record->space)
		printed = wd_type(record, str);
	if (record->plus || record->space)
		printed = sub_type_di(record, di, str);
	free (str);
	return (printed);
}

int	type_u(t_record *record)
{
	unsigned int	u;
	int				printed;
	char			*str;
	char			*padded;

	u = va_arg(record->args, unsigned int);
	if (record->plus || record->hash || record->space)
		return (-1);
	if (u == 0 && record->preci == 0 && record->point && record->width == 0)
		return (0);
	str = kx_itoa(u);
	if (u == 0 && record->preci == 0 && record->point)
		str[0] = '\0';
	if (record->point)
		record->zero = 0;
	if ((record->width <= record->preci) || record->zero)
		padded = "0";
	else
		padded = " ";
	if (record->minus && (record->width > record->preci))
		printed = left_digit(record, str, padded);
	else
		printed = right_digit(record, str, padded);
	free(str);
	return (printed);
}

int	left_right_side(t_record *record, char *str, char side, int mode_c)
{
	int	len;
	int	space;

	len = 0;
	if ((side == 'l') && (!mode_c) && record->preci > (int)ft_strlen(str))
		len += write(1, str, ft_strlen(str));
	else if (side == 'l')
		len += write(1, str, record->preci);
	if (record->width > record->preci)
	{
		space = 0;
		while (space++ < (record->width - record->preci))
			len += write(1, " ", 1);
	}
	if ((side == 'r') && (!mode_c) && record->preci > (int)ft_strlen(str))
		len += write(1, str, ft_strlen(str));
	else if (side == 'r')
		len += write(1, str, record->preci);
	return (len);
}

int	wd_type(t_record *record, char *str)
{
	int		printed;
	char	*padded;

	if (str[0] == '0' && record->preci == 0 && record->point)
		str[0] = '\0';
	if (record->point)
		record->zero = 0;
	if ((record->width <= record->preci) || record->zero)
		padded = "0";
	else
		padded = " ";
	if (record->minus && (record->width > record->preci))
		printed = left_digit(record, str, padded);
	else
		printed = right_digit(record, str, padded);
	return (printed);
}
