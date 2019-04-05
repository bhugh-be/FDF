/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 22:04:07 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/12/04 22:04:09 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free_list(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
	free(lst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*link;
	t_list	*list;
	t_list	*tmp;

	if (!lst || !f)
		return (0);
	tmp = f(lst);
	if (!(list = ft_lstnew(tmp->content, tmp->content_size)))
		return (0);
	link = list;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(list->next = ft_lstnew(tmp->content, tmp->content_size)))
		{
			ft_free_list(link);
			return (0);
		}
		list = list->next;
		lst = lst->next;
	}
	return (link);
}
