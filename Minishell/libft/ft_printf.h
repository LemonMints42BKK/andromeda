/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:55:33 by kchatvet          #+#    #+#             */
/*   Updated: 2022/10/05 21:08:21 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct var_print
{
	va_list	args;
	int		minus;
	int		zero;
	int		point;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		preci;
	int		len;
	int		percent;
	int		dot_zero;
	int		signdi;
}	t_record;

int		ft_printf(const char *fmt, ...);
int		check_type(t_record *record, const char *fmt, int index);
int		left_right_side(t_record *record, char *str, char side, int mode_c);
int		left_digit(t_record *record, char *str, char *padded);
int		right_digit(t_record *record, char *str, char *padded);
int		loop_pad(int len, int n_loop, char *padded);
int		type_c(t_record *record);
int		type_s(t_record *record);
int		type_p(t_record *record);
int		type_di(t_record *record);
int		type_u(t_record *record);
int		type_sbx(t_record *record, int mode_b);
int		type_percent(t_record *record);
char	*kx_itoa(long n);
int		wd_type(t_record *record, char *str);
char	*di_itoa(int n);

#endif
