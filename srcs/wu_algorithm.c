/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:36:09 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/09 17:32:12 by bhugh-be         ###   ########.fr       */
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

int set_alpha(int c, double a)
{
	c &= ~(255 << 24);
	c |= (int)(255 * a) << 24;
	(void)a;
	return (c);
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
	double steep;
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
// printf(">x0:%f y0:%f, x1:%f y1:%f\n", line->x0, line->y0, line->x1, line->y1);
	steep = fabs(line->y1 - line->y0) > fabs(line->x1 - line->x0);

	if (steep)
	{
		ft_swap_double(&line->x0, &line->y0);
		ft_swap_double(&line->y1, &line->x1);
	}
	// printf(">>x0:%f y0:%f, x1:%f y1:%f\n", line->x0, line->y0, line->x1, line->y1);
	if (line->x0 > line->x1)
	{
		ft_swap_double(&line->x0, &line->x1);
		ft_swap_double(&line->y0, &line->y1);
	}
	// printf(">>>x0:%f y0:%f, x1:%f y1:%f\n", line->x0, line->y0, line->x1, line->y1);
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
	if (steep)
	{
		set_pixel(line->data, ypxl1, xpxl1, set_alpha(line->c0, fpart(yend) * xgap));
		// set_pixel(line->data, ypxl1 + 1, xpxl1, set_alpha(line->c0, rfpart(yend) * xgap));
	}
	else
	{
		set_pixel(line->data, xpxl1, ypxl1, set_alpha(line->c0, fpart(yend) * xgap));
		// set_pixel(line->data, xpxl1, ypxl1 + 1, set_alpha(line->c0, rfpart(yend) * xgap));
	}
	intery = yend + gradient;
	xend = round(line->x1);
	yend = line->y1 + gradient * (xend - line->x1);
	xgap = rfpart(line->x1 + 0.5);
	xpxl2 = xend;
	ypxl2 = ipart(yend);
	if (steep)
	{
		set_pixel(line->data, ypxl2, xpxl2, set_alpha(line->c0, fpart(yend) * xgap));
		// set_pixel(line->data, ypxl2 + 1, xpxl2, set_alpha(line->c0, rfpart(yend) * xgap));
	}
	else
	{
		set_pixel(line->data, xpxl2, ypxl2, set_alpha(line->c0, fpart(yend) * xgap));
		// set_pixel(line->data, xpxl2, ypxl2 + 1, set_alpha(line->c0, rfpart(yend) * xgap));
	}
	if (steep)
	{
		x = xpxl1 + 1;
		while (x < xpxl2)
		{
			set_pixel(line->data, ipart(intery), x, set_alpha(line->c0, fpart(intery)));
			set_pixel(line->data, ipart(intery) + 1, x, set_alpha(line->c0, rfpart(intery)));
			intery += gradient;
			x++;
		}
	}
	else
	{
		x = xpxl1 + 1;
		while (x < xpxl2)
		{
			set_pixel(line->data, x, ipart(intery), set_alpha(line->c0, fpart(intery)));
			set_pixel(line->data, x, ipart(intery) + 1, set_alpha(line->c0, rfpart(intery)));
			intery += gradient;
			x++;
		}
	}
}
