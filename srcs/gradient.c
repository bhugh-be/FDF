/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:01:17 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/10 22:26:48 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			percent(int start, int end, int current)
{
	double distance;

	distance = end - start;
	return ((distance)? ((current - start) / distance) : (1.0));
}

int				get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int				get_color(t_line *line, int x, int y)
{
	int			red;
	int			green;
	int			blue;
	double		percent;

	if (fabs(line->y1 - line->y0) > fabs(line->x1 - line->x0))
}
