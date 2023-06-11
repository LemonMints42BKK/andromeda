/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:48:13 by kchatvet          #+#    #+#             */
/*   Updated: 2022/09/08 10:21:37 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_c(t_record *record)
{
	char	c;
	int		printed;

	c = va_arg(record->args, int);
	record->preci = 1;
	if (record->zero || record->hash || record->space || record->plus)
		return (-1);
	if (record->minus)
		printed = left_right_side(record, &c, 'l', 1);
	else
		printed = left_right_side(record, &c, 'r', 1);
	return (printed);
}

int	type_s(t_record *record)
{
	char	*str;
	int		printed;

	str = va_arg(record->args, char *);
	if (!str)
		str = "(null)";
	if (record->plus || record->hash)
		return (-1);
	if (!record->point || record->preci > (int)ft_strlen(str))
		record->preci = ft_strlen(str);
	if (record->minus)
		printed = left_right_side(record, str, 'l', 0);
	else
		printed = left_right_side(record, str, 'r', 0);
	if (printed < 0)
		return (-1);
	return (printed);
}

int	type_percent(t_record *record)
{
	int	printed;

	record->preci = 1;
	if (record->minus)
		printed = left_right_side(record, "%", 'l', 0);
	else
		printed = left_right_side(record, "%", 'r', 0);
	if (printed < 0)
		return (-1);
	return (printed);
}
