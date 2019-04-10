/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:28:38 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/10 21:09:14 by bhugh-be         ###   ########.fr       */
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
	t_values	values;


	ft_memset(&values, 0, sizeof(t_values));
	values.mlx_ptr = mlx_init();
	values.img_ptr = mlx_new_image(values.mlx_ptr, WIDTH, HEIGHT);
	values.win_ptr = mlx_new_window(values.mlx_ptr, WIDTH, HEIGHT, "....");
	values.data = mlx_get_data_addr(values.img_ptr, &values.bits_per_pixel, &values.size_line, &values.endian);
	get_dots(av[1], &values);
	// for (int j = 0; j < values.h; j++)
    // {
    //     for (int i = 0; i < values.w; i++)
    //         printf("%3d,0x%x", values.dots[j][i].z, (unsigned)values.dots[j][i].c);
    //     printf("\n");
    // }
	drawmatrix(&values);
	mlx_put_image_to_window(values.mlx_ptr, values.win_ptr, values.img_ptr, 0, 0);
	mlx_hook(values.win_ptr, 4, 0, mouse_press, &values);
	mlx_hook(values.win_ptr, 5, 0, mouse_release, &values);
	mlx_hook(values.win_ptr, 6, 0, mouse_move, &values);
	mlx_hook(values.win_ptr, 17, 0, close_window, &values);
	mlx_hook(values.win_ptr, 2, 0, key_press, &values);
	mlx_hook(values.win_ptr, 3, 0, key_release, &values);
	mlx_loop(values.mlx_ptr);
	return (0);
}
