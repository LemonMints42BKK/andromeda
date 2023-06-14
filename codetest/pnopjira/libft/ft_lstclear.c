/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:53:09 by kchatvet          #+#    #+#             */
/*   Updated: 2022/03/18 21:42:24 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*dummy;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		dummy = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = dummy;
	}
}
