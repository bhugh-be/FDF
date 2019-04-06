/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:28:38 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/05 18:28:40 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			argb(int a, int r, int g, int b)
{
	int		color;

	color = b;
	color |= g << 8;
	color |= r << 16;
	color |= a << 24;
	return (color);
}

int			main(void)
{
	int		i;
	void	*mlx_ptr;
	void	*win_ptr;
	t_line	line;

	i = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2000, 1500, "....");
	line.x0 = 30;
	line.y0 = 30;
	line.x1 = 1700;
	line.y1 = 200;
	line.c0 = argb(0, 255, 0, 0);
	line.mlx = mlx_ptr;
	line.win = win_ptr;
	drawline(&line);
	mlx_loop(mlx_ptr);
	return (0);
}
