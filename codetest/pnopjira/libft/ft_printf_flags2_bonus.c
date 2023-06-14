/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:47:23 by kchatvet          #+#    #+#             */
/*   Updated: 2022/09/15 01:09:28 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	str_print_hex(unsigned int h, int mode_b)
{
	int		len;

	len = 0;
	if (h >= 16)
		len += str_print_hex(h / 16, mode_b);
	if (mode_b)
		ft_putchar_fd("0123456789ABCDEF"[h % 16], 1);
	else
		ft_putchar_fd("0123456789abcdef"[h % 16], 1);
	len++;
	return (len);
}

char	*hex_itoa(unsigned int h, int mode_b)
{
	char			*str;
	long			l;
	unsigned int	nbr;

	l = 16;
	nbr = 1;
	while (h / l)
	{
		l *= 16;
		nbr++;
	}
	str = malloc(sizeof(char) * (nbr + 1));
	if (!str)
		return (NULL);
	str[nbr] = '\0';
	while (nbr)
	{
		if (mode_b)
			str[nbr - 1] = ("0123456789ABCDEF"[h % 16]);
		else
			str[nbr - 1] = ("0123456789abcdef"[h % 16]);
		h /= 16;
		nbr--;
	}
	return (str);
}

int	type_sbx(t_record *record, int mode_b)
{
	unsigned int	h;
	int				printed;
	char			*hex_str;

	h = va_arg(record->args, unsigned int);
	printed = 0;
	if (record->plus || record->space)
		return (-1);
	if (!record->hash)
	{
		hex_str = hex_itoa(h, mode_b);
		printed = wd_type(record, hex_str);
		free (hex_str);
	}
	if (record->hash && h != 0)
	{
		if (mode_b)
			printed = write(1, "0X", 2);
		else
			printed = write(1, "0x", 2);
	}
	if (record->hash)
			printed += str_print_hex(h, mode_b);
	return (printed);
}
