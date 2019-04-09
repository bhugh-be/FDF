/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:28:38 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/08 23:35:00 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int argb(int a, int r, int g, int b)
{
	int color;

	color = b;
	color |= g << 8;
	color |= r << 16;
	color |= a << 24;
	return (color);
}

int main(int ac, char **av)
{
	(void)ac;

	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	int bits_per_pixel;
	char *data;
	int size_line;
	int		endian;
	t_dot	**dot;
	int		h;
	int		w;
	t_values	values;


	mlx_ptr = mlx_init();
	img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "....");
	data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	dot = get_dots(av[1], &h, &w);
	ft_memset(&values, 0, sizeof(t_values));
	drawmatrix(data, dot, h, w);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_hook(win_ptr, 4, 0, mouse_press, &values);
	mlx_loop(mlx_ptr);
	return (0);
}
