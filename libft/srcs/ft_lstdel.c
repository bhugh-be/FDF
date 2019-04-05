/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:31:45 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/12/04 19:31:47 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *blst;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		blst = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		*alst = blst;
		free(*alst);
	}
	*alst = 0;
}
