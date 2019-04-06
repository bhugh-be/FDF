/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:41:35 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/05 20:41:39 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					set_alpha(int c, double a)
{
	c &= ~(255 << 24);
	c |= (int)(255 * a) << 24;
	return (c);
}

double			round(double n)
{
	return (floor(n + 0.5));
}

double			ipart(double n)
{
	return (floor(n));
}

double			fpart(double n)
{
	return (n - floor(n));
}

double			rfpart(double n)
{
	return (1 - fpart(n));
}

void			drawline(t_line *line)
{
	double		steep;
	double		dx;
	double		dy;
	double		xend;
	double		yend;
	double 		gradient;
	double		xgap;
	double		xpxl1;
	double		xpxl2;
	double		ypxl1;
	double		ypxl2;
	double		intery;
	double		x;


	steep = fabs(line->y1 - line->y0) > fabs(line->x1 - line->x0);

	if (steep)
	{
		ft_swap_double(&line->x0, &line->y0);
		ft_swap_double(&line->y1, &line->x0);
	}
	if (line->x0 > line->x1)
	{
		ft_swap_double(&line->x0, &line->x1);
		ft_swap_double(&line->y0, &line->y0);
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
	if (steep)
	{
		mlx_pixel_put(line->mlx, line->win, ypxl1, xpxl1, set_alpha(line->c0, rfpart(yend) * xgap));
		mlx_pixel_put(line->mlx, line->win, ypxl1+1, xpxl1, set_alpha(line->c0, fpart(yend) * xgap));
	}
	else
	{
		mlx_pixel_put(line->mlx, line->win, xpxl1, ypxl1, set_alpha(line->c0, rfpart(yend) * xgap));
		mlx_pixel_put(line->mlx, line->win, xpxl1, ypxl1+1, set_alpha(line->c0, fpart(yend) * xgap));
	}
	intery = yend + gradient;
	xend = round(line->x1);
	yend = line->y1 + gradient * (xend - line->x1);
	xgap = rfpart(line->x1 + 0.5);
	xpxl2 = xend;
	ypxl2 = ipart(yend);
	if (steep)
	{
		mlx_pixel_put(line->mlx, line->win, ypxl2, xpxl2, set_alpha(line->c0, rfpart(yend) * xgap));
		mlx_pixel_put(line->mlx, line->win, ypxl2+1, xpxl2, set_alpha(line->c0, fpart(yend) * xgap));
	}
	else
	{
		mlx_pixel_put(line->mlx, line->win, xpxl2, ypxl2, set_alpha(line->c0, rfpart(yend) * xgap));
		mlx_pixel_put(line->mlx, line->win, xpxl2, ypxl2+1, set_alpha(line->c0, fpart(yend) * xgap));
	}
	if (steep)
	{
		x = xpxl1+1;
		while (x < xpxl2)
		{
			mlx_pixel_put(line->mlx, line->win, ipart(intery), x, set_alpha(line->c0, rfpart(intery)));
			mlx_pixel_put(line->mlx, line->win, ipart(intery)+1, x, set_alpha(line->c0, fpart(intery)));
			intery+=gradient;
			x++;
		}
	}
	else
	{
		x = xpxl1+1;
		while (x < xpxl2)
		{
			mlx_pixel_put(line->mlx, line->win, x, ipart(intery), set_alpha(line->c0, rfpart(intery)));
			mlx_pixel_put(line->mlx, line->win, x, ipart(intery)+1, set_alpha(line->c0, fpart(intery)));
			intery+=gradient;
			x++;
		}
	}





}
