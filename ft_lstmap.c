/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:39:32 by khermann          #+#    #+#             */
/*   Updated: 2020/11/23 18:36:46 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new;

	if (!lst)
		return (0);
	if (!(new = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&lst, (*del));
		return (0);
	}
	new_lst = new;
	lst = lst->next;
	while (lst && new)
	{
		if (!(new->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_lst, (*del));
			ft_lstclear(&lst, (*del));
			return (0);
		}
		lst = lst->next;
		new = new->next;
	}
	return (new_lst);
}
