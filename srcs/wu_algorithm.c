/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:36:09 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/11 22:48:11 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 		set_pixel(char *data, int x, int y, int color)
{
	int 	*img;

	if (x < 0 || y < 0 || x > WIDTH - 1 || y > HEIGHT - 1)
		return ;
	img = (int *)data;
	img[x + y * WIDTH] = color;
}

double round(double n)
{
	return (floor(n + 0.5));
}

double ipart(double n)
{
	return (floor(n));
}

double fpart(double n)
{
	return (n - floor(n));
}

double rfpart(double n)
{
	return (1 - fpart(n));
}

void drawline(t_line *line)
{
	double dx;
	double dy;
	double xend;
	double yend;
	double gradient;
	double xgap;
	double xpxl1;
	double xpxl2;
	double ypxl1;
	double ypxl2;
	double intery;
	double x;
	line->steep = fabs(line->y1 - line->y0) > fabs(line->x1 - line->x0);

	if (line->steep)
	{
		ft_swap_double(&line->x0, &line->y0);
		ft_swap_double(&line->y1, &line->x1);
		// ft_swap(&line->c0, &line->c1);
	}
	if (line->x0 > line->x1)
	{
		ft_swap_double(&line->x0, &line->x1);
		ft_swap_double(&line->y0, &line->y1);
		ft_swap(&line->c0, &line->c1);
	}
	dx = line->x1 - line->x0;
	dy = line->y1 - line->y0;
	if (dx == 0)
		gradient = 1.0;
	else
		gradient = dy / dx;
	xend = round(line->x0);
	yend = line->y0 + gradient * (xend - line->x0);
	xgap = rfpart(line->x0 + 0.5);
	xpxl1 = xend;
	ypxl1 = ipart(yend);
	if (line->steep)
	{
		set_pixel(line->data, ypxl1, xpxl1, get_color(line, ypxl1, xpxl1, fpart(yend) * xgap));
		// set_pixel(line->data, ypxl1 + 1, xpxl1, get_color(line, rfpart(yend) * xgap));
	}
	else
	{
		set_pixel(line->data, xpxl1, ypxl1, get_color(line, xpxl1, ypxl1, fpart(yend) * xgap));
		// set_pixel(line->data, xpxl1, ypxl1 + 1, get_color(line, rfpart(yend) * xgap));
	}
	intery = yend + gradient;
	xend = round(line->x1);
	yend = line->y1 + gradient * (xend - line->x1);
	xgap = rfpart(line->x1 + 0.5);
	xpxl2 = xend;
	ypxl2 = ipart(yend);
	if (line->steep)
	{
		set_pixel(line->data, ypxl2, xpxl2, get_color(line, ypxl2, xpxl2, fpart(yend) * xgap));
		// set_pixel(line->data, ypxl2 + 1, xpxl2, get_color(line, rfpart(yend) * xgap));
	}
	else
	{
		set_pixel(line->data, xpxl2, ypxl2, get_color(line, xpxl2, ypxl2, fpart(yend) * xgap));
		// set_pixel(line->data, xpxl2, ypxl2 + 1, get_color(line, rfpart(yend) * xgap));
	}
	if (line->steep)
	{
		x = xpxl1 + 1;
		while (x < xpxl2)
		{
			set_pixel(line->data, ipart(intery), x, get_color(line, ipart(intery), x, fpart(intery)));
			set_pixel(line->data, ipart(intery) + 1, x, get_color(line, ipart(intery) + 1, x, rfpart(intery)));
			intery += gradient;
			x++;
		}
	}
	else
	{
		x = xpxl1 + 1;
		while (x < xpxl2)
		{
			set_pixel(line->data, x, ipart(intery), get_color(line, x, ipart(intery), fpart(intery)));
			set_pixel(line->data, x, ipart(intery) + 1, get_color(line, x, ipart(intery) + 1, rfpart(intery)));
			intery += gradient;
			x++;
		}
	}
}
