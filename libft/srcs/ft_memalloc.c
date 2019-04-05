/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:58:19 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/11/27 21:58:22 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int	*mem;

	mem = malloc(size);
	if (mem == 0)
		return (0);
	else
		ft_bzero(mem, size);
	return (mem);
}
