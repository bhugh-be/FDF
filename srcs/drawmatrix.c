/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmatrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:55:22 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/09 19:28:56 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		drawmatrix(t_values *values)
{
	t_line	line;
	int 	i;
	int 	j;

	j = 0;
	line.data = values->data;
	while (j < values->h)
	{
		i = 0;
		while (i < values->w)
		{
			line.x0 = i * SCALE;
			line.y0 = j * SCALE;
			line.c0 = values->dots[j][i].c;
			line.z0 = values->dots[j][i].z;
			if (i + 1 < values->w)
			{
				line.x1 = (i + 1) * SCALE;
				line.y1 = j * SCALE;
				line.c1 = values->dots[j][i + 1].c;
				line.z1 = values->dots[j][i + 1].z;
				drawline(&line);
			}
			if (j + 1 < values->h)
			{
				line.x1 = i * SCALE;
				line.y1 = (j + 1) * SCALE;
				line.c1 = values->dots[j + 1][i].c;
				line.z1 = values->dots[j + 1][i].z;
				drawline(&line);
			}
			i++;
		}
		j++;
	}
}
