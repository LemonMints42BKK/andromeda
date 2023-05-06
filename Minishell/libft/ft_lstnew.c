/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:34:08 by kchatvet          #+#    #+#             */
/*   Updated: 2022/03/17 13:40:11 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nodest;

	nodest = malloc(sizeof(t_list));
	if (!nodest)
		return (NULL);
	nodest->content = content;
	nodest->next = NULL;
	return (nodest);
}
