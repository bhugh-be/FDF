/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:58:51 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/01/29 17:58:54 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_sqrt(size_t num)
{
	size_t	i;

	i = 1;
	if (num == 0)
		return (0);
	while (i * i < num)
		i++;
	return (i);
}
