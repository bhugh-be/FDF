/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmatrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:55:22 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/10 21:10:56 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate(t_line *line, t_values *values, int dx, int dy)
{
	int		d0[3];
	int		d1[3];

	d0[0] = line->x0;
	d0[1] = line->y0;
	d0[2] = line->z0;
	d1[0] = line->x1;
	d1[1] = line->y1;
	d1[2] = line->z1;
	line->y0 = (d0[1] * cos(dy * R_KOEF) + d0[2] * sin(dy * R_KOEF)) + values->offy;
	d0[2] = (-d0[1] * sin(dy * R_KOEF) + d0[2] * cos(dy * R_KOEF));
	line->x0 = (d0[0] * cos(dx * R_KOEF) + d0[2] * sin(dx * R_KOEF)) + values->offx;
	line->z0 = (-d0[0] * sin(dx * R_KOEF) + d0[2] * cos(dx * R_KOEF));	
	line->y1 = (d1[1] * cos(dy * R_KOEF) + d1[2] * sin(dy * R_KOEF)) + values->offy;
	d1[2] = (-d1[1] * sin(dy * R_KOEF) + d1[2] * cos(dy * R_KOEF));
	line->x1 = (d1[0] * cos(dx * R_KOEF) + d1[2] * sin(dx * R_KOEF)) + values->offx;
	line->z1 = (-d1[0] * sin(dx * R_KOEF) + d1[2] * cos(dx * R_KOEF));
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
			line.x0 = ((i - (values->w - 1) / 2)) * values->scale;
			line.y0 = ((j - (values->h - 1) / 2)) * values->scale;
			line.z0 = values->dots[j][i].z * values->scale;
			line.c0 = values->dots[j][i].c;			
			if (i + 1 < values->w)
			{
				line.x1 = ((i + 1 - (values->w - 1) / 2)) * values->scale;
				line.y1 = ((j - (values->h - 1) / 2)) * values->scale;
				line.z1 = values->dots[j][i + 1].z * values->scale;
				line.c1 = values->dots[j][i + 1].c;
				rotate(&line, values, values->dx, values->dy);
				drawline(&line);
			}
			line.x0 = ((i - (values->w - 1) / 2)) * values->scale;
			line.y0 = ((j - (values->h - 1) / 2)) * values->scale;
			line.z0 = values->dots[j][i].z * values->scale;
			line.c0 = values->dots[j][i].c;	
			if (j + 1 < values->h)
			{
				line.x1 = ((i - (values->w - 1) / 2)) * values->scale;
				line.y1 = ((j + 1 - (values->h - 1) / 2)) * values->scale;
				line.z1 = values->dots[j + 1][i].z * values->scale;
				line.c1 = values->dots[j + 1][i].c;
				rotate(&line, values, values->dx, values->dy);
				drawline(&line);
			}
			i++;
		}
		j++;
	}
}
