/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:56:15 by kchatvet          #+#    #+#             */
/*   Updated: 2022/03/20 00:32:15 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*dummy;

	if (!lst)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		dummy = ft_lstnew(f(lst->content));
		if (!dummy)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, dummy);
		lst = lst->next;
	}
	return (new_lst);
}
