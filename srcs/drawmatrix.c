/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmatrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:55:22 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/21 18:00:21 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			cross_window(t_line *l, t_values *v)
{
	if (!(l->x0 > v->win_w || l->x0 < 0 || l->y0 > v->win_h || l->y0 < 0) ||
		!(l->x1 > v->win_w || l->x1 < 0 || l->y1 > v->win_h || l->y1 < 0))
		return (1);
	if (cross(l->x0, l->x1, 0, v->win_w) && cross(l->y0, l->y1, 0, 0) &&
		(((l->x1 - l->x0) * (0 - l->y0) - (l->y1 - l->y0) * (0 - l->x0)) *
		((l->x1 - l->x0) * (0 - l->y0) - (l->y1 - l->y0) * (v->win_w - l->x0)))
		<= 0 && ((v->win_w - 0) * (l->y0 - 0) - (0 - 0) * (l->x0 - 0)) *
		((v->win_w - 0) * (l->y1 - 0) - (0 - 0) * (l->x1 - 0)) <= 0)
		return (1);
	if (cross(l->x0, l->x1, 0, 0) && cross(l->y0, l->y1, 0, v->win_h) &&
		(((l->x1 - l->x0) * (0 - l->y0) - (l->y1 - l->y0) * (0 - l->x0)) *
		((l->x1 - l->x0) * (v->win_h - l->y0) - (l->y1 - l->y0) * (0 - l->x0)))
		<= 0 && ((0 - 0) * (l->y0 - 0) - (v->win_h - 0) * (l->x0 - 0)) *
		((0 - 0) * (l->y1 - 0) - (v->win_h - 0) * (l->x1 - 0)) <= 0)
		return (1);
	if (cross(l->x0, l->x1, v->win_w, v->win_w) &&
		cross(l->y0, l->y1, 0, v->win_h) && (((l->x1 - l->x0) * (0 - l->y0) -
		(l->y1 - l->y0) * (v->win_w - l->x0)) * ((l->x1 - l->x0) *
		(v->win_h - l->y0) - (l->y1 - l->y0) * (v->win_w - l->x0))) <= 0 &&
		((v->win_w - v->win_w) * (l->y0 - 0) - (v->win_h - 0) *
		(l->x0 - v->win_w)) * ((v->win_w - v->win_w) * (l->y1 - 0)
		- (v->win_h - 0) * (l->x1 - v->win_w)) <= 0)
		return (1);
	return (0);
}

void		rotate(t_line *line, t_values *values)
{
	int d0[3];
	int d1[3];

	d0[0] = line->x0;
	d0[1] = line->y0;
	d0[2] = line->z0;
	d1[0] = line->x1;
	d1[1] = line->y1;
	d1[2] = line->z1;
	line->y0 = (d0[1] * cos(values->dy * R_KOEF) + d0[2] *
		sin(values->dy * R_KOEF)) + values->offy;
	d0[2] = (-d0[1] * sin(values->dy * R_KOEF) + d0[2] *
		cos(values->dy * R_KOEF));
	line->x0 = (d0[0] * cos(values->dx * R_KOEF) + d0[2] *
		sin(values->dx * R_KOEF)) + values->offx;
	line->z0 = (-d0[0] * sin(values->dx * R_KOEF) + d0[2] *
		cos(values->dx * R_KOEF));
	line->y1 = (d1[1] * cos(values->dy * R_KOEF) + d1[2] *
		sin(values->dy * R_KOEF)) + values->offy;
	d1[2] = (-d1[1] * sin(values->dy * R_KOEF) + d1[2] *
		cos(values->dy * R_KOEF));
	line->x1 = (d1[0] * cos(values->dx * R_KOEF) + d1[2] *
		sin(values->dx * R_KOEF)) + values->offx;
	line->z1 = (-d1[0] * sin(values->dx * R_KOEF) + d1[2] *
		cos(values->dx * R_KOEF));
}

void		draw_line_right(t_values *values, int i, int j, t_line *line)
{
	line->x0 = ((i - (values->w - 1) / 2)) * values->scale;
	line->y0 = ((j - (values->h - 1) / 2)) * values->scale;
	line->z0 = values->dots[j][i].hz * values->scale;
	line->c0 = values->dots[j][i].c;
	if (i + 1 < values->w)
	{
		line->x1 = ((i + 1 - (values->w - 1) / 2)) * values->scale;
		line->y1 = ((j - (values->h - 1) / 2)) * values->scale;
		line->z1 = values->dots[j][i + 1].hz * values->scale;
		line->c1 = values->dots[j][i + 1].c;
		rotate(line, values);
		if (cross_window(line, values))
			wu_algorithm(line, values);
	}
}

void		draw_line_down(t_values *values, int i, int j, t_line *line)
{
	line->x0 = ((i - (values->w - 1) / 2)) * values->scale;
	line->y0 = ((j - (values->h - 1) / 2)) * values->scale;
	line->z0 = values->dots[j][i].hz * values->scale;
	line->c0 = values->dots[j][i].c;
	if (j + 1 < values->h)
	{
		line->x1 = ((i - (values->w - 1) / 2)) * values->scale;
		line->y1 = ((j + 1 - (values->h - 1) / 2)) * values->scale;
		line->z1 = values->dots[j + 1][i].hz * values->scale;
		line->c1 = values->dots[j + 1][i].c;
		rotate(line, values);
		if (cross_window(line, values))
			wu_algorithm(line, values);
	}
}

void		drawmatrix(t_values *values)
{
	t_line	line;
	int		i;
	int		j;

	j = 0;
	ft_bzero(values->data, values->win_w * values->win_h * 4);
	line.data = values->data;
	while (j < values->h)
	{
		i = 0;
		while (i < values->w)
		{
			draw_line_right(values, i, j, &line);
			draw_line_down(values, i, j, &line);
			i++;
		}
		j++;
	}
}
