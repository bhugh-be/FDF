/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmatrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:55:22 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/09 22:28:15 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate(t_line *line, int dx, int dy)
{
	line->y0 = line->y0 * cos(dy * R_KOEF) + line->z0 * sin(dy * R_KOEF);
	line->z0 = -line->y0 * sin(dy * R_KOEF) + line->z0 * cos(dy * R_KOEF);
	line->x0 = line->x0 * cos(dx * R_KOEF) + line->z0 * sin(dx * R_KOEF);
	line->z0 = -line->x0 * sin(dx * R_KOEF) + line->z0 * cos(dx * R_KOEF);
	line->y1 = line->y1 * cos(dy * R_KOEF) + line->z1 * sin(dy * R_KOEF);
	line->z1 = -line->y1 * sin(dy * R_KOEF) + line->z1 * cos(dy * R_KOEF);
	line->x1 = line->x1 * cos(dx * R_KOEF) + line->z1 * sin(dx * R_KOEF);
	line->z1 = -line->x1 * sin(dx * R_KOEF) + line->z1 * cos(dx * R_KOEF);
}

void		drawmatrix(t_values *values)
{
	t_line	line;
	int 	i;
	int 	j;

	j = 0;
	ft_bzero(values->data, WIDTH * HEIGHT * 4);
	line.data = values->data;
	while (j < values->h)
	{
		i = 0;
		while (i < values->w)
		{
			line.x0 = i * SCALE + 6300;
			line.y0 = j * SCALE + 6300;
			line.z0 = values->dots[j][i].z;
			line.c0 = values->dots[j][i].c;			
			if (i + 1 < values->w)
			{
				line.x1 = (i + 1) * SCALE + 6300;
				line.y1 = j * SCALE + 6300;
				line.z1 = values->dots[j][i + 1].z;
				line.c1 = values->dots[j][i + 1].c;
				rotate(&line, values->dx, values->dy);
				drawline(&line);
			}
			if (j + 1 < values->h)
			{
				line.x1 = i * SCALE + 6300;
				line.y1 = (j + 1) * SCALE + 6300;
				line.z1 = values->dots[j + 1][i].z;
				line.c1 = values->dots[j + 1][i].c;
				rotate(&line, values->dx, values->dy);
				drawline(&line);
			}
			i++;
		}
		j++;
	}
}
