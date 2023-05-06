/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:02:30 by kchatvet          #+#    #+#             */
/*   Updated: 2022/09/15 15:09:20 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initial(t_record *record)
{
	record->minus = 0;
	record->zero = 0;
	record->point = 0;
	record->hash = 0;
	record->space = 0;
	record->plus = 0;
	record->width = 0;
	record->preci = 0;
	record->len = 0;
	record->percent = 0;
	record->dot_zero = 0;
	record->signdi = 0;
}

int	in_type(char conv)
{
	char	*str_type;
	int		i;

	str_type = "cspdiuxX%";
	i = 0;
	while (str_type[i] != '\0')
	{
		if (str_type[i] == conv)
			return (1);
		i++;
	}
	return (0);
}

int	check_preci_width(t_record *record, const char *fmt, int index, char pw)
{
	int	i;

	if (pw == 'p')
	{
		record->point = 1;
		record->preci = ft_atoi(&fmt[++index]);
		if (record->preci == 0)
			record->dot_zero = 0;
	}
	if (pw == 'w')
		record->width = ft_atoi(&fmt[index]);
	i = index;
	while (ft_isdigit(fmt[i]))
		i++;
	return (--i);
}

int	eva_format(t_record *record, const char *fmt, int index)
{
	initial(record);
	while (fmt[++index])
	{
		if (fmt[index] == '-')
			record->minus = 1;
		else if (fmt[index] == '0')
			record->zero = 1;
		else if (fmt[index] == '#')
			record->hash = 1;
		else if (fmt[index] == ' ')
			record->space = 1;
		else if (fmt[index] == '+')
			record->plus = 1;
		else if (fmt[index] == '.')
			index = check_preci_width(record, fmt, index, 'p');
		else if (ft_isdigit(fmt[index]))
			index = check_preci_width(record, fmt, index, 'w');
		else if (in_type(fmt[index]))
			break ;
		else
			return (index);
	}
	record->len = check_type(record, fmt, index);
	return (index);
}

int	ft_printf(const char *fmt, ...)
{
	t_record	*record;
	int			index;
	int			printed;

	record = (t_record *)malloc(sizeof(t_record));
	if (!record)
		return (-1);
	va_start(record->args, fmt);
	initial(record);
	index = -1;
	printed = 0;
	while (fmt[++index])
	{
		if (fmt[index] == '%')
			index = eva_format(record, fmt, index);
		else
			record->len = write(1, &fmt[index], 1);
		printed += record->len;
	}
	va_end(record->args);
	index = record->len;
	free (record);
	if (index < 0)
		return (-1);
	return (printed);
}
