/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:01:17 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/11 22:29:58 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			percentage(int start, int end, int current)
{
	double distance;

	distance = end - start;
	return ((distance)? ((current - start) / distance) : (1.0));
}

int				get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int				get_color(t_line *line, int x, int y, double alpha)
{
	int			red;
	int			green;
	int			blue;
	double		percent;

	if (line->c0 == line->c1)
		return (line->c0 | (int)(alpha * 255) << 24);
	percent = percentage(line->x0, line->x1, (line->steep) ? (y) : (x));
	blue = get_light(line->c0 & 255, line->c1 & 255, percent);
	green = get_light(line->c0 >> 8 & 255, line->c1 >> 8 & 255, percent);
	red = get_light(line->c0 >> 16 & 255, line->c1 >> 16 & 255, percent);
	return (((int)(alpha * 255) << 24) | (red << 16) | (green << 8) | blue);
}
