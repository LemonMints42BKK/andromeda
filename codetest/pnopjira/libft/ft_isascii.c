/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:24:42 by kchatvet          #+#    #+#             */
/*   Updated: 2022/02/17 16:15:25 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int ch)
{
	if (!(ch >= 0 && ch <= 127))
		return (0);
	return (1);
}