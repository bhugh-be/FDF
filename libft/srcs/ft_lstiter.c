/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:42:22 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/12/04 21:42:24 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *lst1;

	if (!lst || !f)
		return ;
	while (lst)
	{
		lst1 = lst->next;
		f(lst);
		lst = lst1;
	}
}
