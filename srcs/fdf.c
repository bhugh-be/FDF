/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:28:38 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/12 17:25:01 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_values *values)
{
	values->offx = values->win_w / 2;
	values->offy = values->win_h  / 2;
	if (values->h < values->w)
		values->scale = values->win_w / values->w;
	else
		values->scale = values->win_h / values->h;
	values->dx  = 0;
	values->dy = 0;
}

int main(int ac, char **av)
{
	(void)ac;
	t_values	values;


	ft_memset(&values, 0, sizeof(t_values));
	get_dots(av[1], &values);
	set_default(&values);
	values.mlx_ptr = mlx_init();
	values.img_ptr = mlx_new_image(values.mlx_ptr, values.win_w, values.win_h);
	values.win_ptr = mlx_new_window(values.mlx_ptr, values.win_w, values.win_h, "....");
	values.data = mlx_get_data_addr(values.img_ptr, &values.bits_per_pixel, &values.size_line, &values.endian);
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
