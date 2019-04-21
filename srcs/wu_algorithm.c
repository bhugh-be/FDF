/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:36:09 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/21 19:20:16 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_pixel(t_values *values, int x, int y, int color)
{
	int		*img;

	if (x < 0 || y < 0 || x > values->win_w - 1 || y > values->win_h - 1)
		return ;
	img = (int *)values->data;
	img[x + y * values->win_w] = color;
}

void		swap_dots(t_line *line)
{
	line->steep = fabs(line->y1 - line->y0) > fabs(line->x1 - line->x0);
	if (line->steep)
	{
		ft_swap_double(&line->x0, &line->y0);
		ft_swap_double(&line->y1, &line->x1);
	}
	if (line->x0 > line->x1)
	{
		ft_swap_double(&line->x0, &line->x1);
		ft_swap_double(&line->y0, &line->y1);
		ft_swap(&line->c0, &line->c1);
	}
}

void		draw_line(t_line *line, t_values *values)
{
	line->xpxl1++;
	if (line->steep)
		while (line->xpxl1 < line->xpxl2)
		{
			set_pixel(values, ipart(line->intery), line->xpxl1,
get_color(line, ipart(line->intery), line->xpxl1, fpart(line->intery)));
			set_pixel(values, ipart(line->intery) + 1, line->xpxl1,
get_color(line, ipart(line->intery) + 1, line->xpxl1, rfpart(line->intery)));
			line->intery += line->gradient;
			line->xpxl1++;
		}
	else
		while (line->xpxl1 < line->xpxl2)
		{
			set_pixel(values, line->xpxl1, ipart(line->intery),
get_color(line, line->xpxl1, ipart(line->intery), fpart(line->intery)));
			set_pixel(values, line->xpxl1, ipart(line->intery) + 1,
get_color(line, line->xpxl1, ipart(line->intery) + 1, rfpart(line->intery)));
			line->intery += line->gradient;
			line->xpxl1++;
		}
}

void		draw_dots(t_line *line, t_values *values)
{
	double yend;
	double xgap;

	(void)values;
	line->xpxl1 = round(line->x0);
	yend = line->y0 + line->gradient * (line->xpxl1 - line->x0);
	line->intery = yend + line->gradient;
	xgap = rfpart(line->x0 + 0.5);
	line->ypxl1 = ipart(yend);
	if (line->steep)
		set_pixel(values, line->ypxl1, line->xpxl1,
			get_color(line, line->ypxl1, line->xpxl1, fpart(yend) * xgap));
	else
		set_pixel(values, line->xpxl1, line->ypxl1,
			get_color(line, line->xpxl1, line->ypxl1, fpart(yend) * xgap));
	line->xpxl2 = round(line->x1);
	yend = line->y1 + line->gradient * (line->xpxl2 - line->x1);
	xgap = rfpart(line->x1 + 0.5);
	line->ypxl2 = ipart(yend);
	if (line->steep)
		set_pixel(values, line->ypxl2, line->xpxl2,
			get_color(line, line->ypxl2, line->xpxl2, fpart(yend) * xgap));
	else
		set_pixel(values, line->xpxl2, line->ypxl2,
			get_color(line, line->xpxl2, line->ypxl2, fpart(yend) * xgap));
}

void		wu_algorithm(t_line *line, t_values *values)
{
	swap_dots(line);
	line->gradient = ((line->x1 - line->x0) == 0) ? (1.0) :
		((line->y1 - line->y0) / (line->x1 - line->x0));
	draw_dots(line, values);
	draw_line(line, values);
}
