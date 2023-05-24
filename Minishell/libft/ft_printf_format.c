/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:45:42 by kchatvet          #+#    #+#             */
/*   Updated: 2022/09/12 21:33:07 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	check_type(t_record *record, const char *fmt, int index)
{
	if (fmt[index] == 'c')
		return (type_c(record));
	else if (fmt[index] == 's')
		return (type_s(record));
	else if (fmt[index] == 'p')
		return (type_p(record));
	else if (fmt[index] == 'd' || fmt[index] == 'i')
		return (type_di(record));
	else if (fmt[index] == 'u')
		return (type_u(record));
	else if (fmt[index] == 'x')
		return (type_sbx(record, 0));
	else if (fmt[index] == 'X')
		return (type_sbx(record, 1));
	else if (fmt[index] == '%')
		return (type_percent(record));
	else
		return (-1);
}

static int	ptr_print_hex(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
		len += ptr_print_hex(ptr / 16);
	ft_putchar_fd("0123456789abcdef"[ptr % 16], 1);
	len++;
	return (len);
}

static int	count_print_hex(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
		len += count_print_hex(ptr / 16);
	len++;
	return (len);
}

int	type_p(t_record *record)
{
	unsigned long	ptr;
	int				printed;

	ptr = (unsigned long)va_arg(record->args, void *);
	if (record->zero || record->point || record->hash)
		return (-1);
	if (record->space || record->plus)
		return (-1);
	record->preci = count_print_hex(ptr) + 2;
	if (record->minus)
	{
		printed = write(1, "0x", 2);
		printed += ptr_print_hex(ptr);
		printed += left_right_side(record, "", 'l', 0);
	}
	else
	{
		printed = left_right_side(record, "", 'r', 0);
		printed += write(1, "0x", 2);
		printed += ptr_print_hex(ptr);
	}
	return (printed);
}
