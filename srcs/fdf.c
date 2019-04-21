/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:28:38 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/20 20:11:33 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			set_default(t_values *values)
{
	values->offx = values->win_w / 2;
	values->offy = values->win_h / 2;
	if (values->h < values->w)
		values->scale = values->win_w / values->w;
	else
		values->scale = values->win_h / values->h;
	values->dx = 0;
	values->dy = 0;
}

int				play(t_values *values)
{
	if (values->wav_file == 0)
	{
		ft_putendl("no audio.wav specified");
		ft_putendl("usage: fdf map [audio.wav]");
		return (0);
	}
	if ((values->wav = open(values->wav_file, O_RDONLY)) == -1)
		ft_die("can't open wav");
	validation_wav(values);
	port_audio_open(values);
	return (0);
}

void			mlx_initialization(t_values *values)
{
	values->mlx_ptr = mlx_init();
	values->img_ptr = mlx_new_image(values->mlx_ptr,
		values->win_w, values->win_h);
	values->win_ptr = mlx_new_window(values->mlx_ptr,
		values->win_w, values->win_h, "....");
	values->data = mlx_get_data_addr(values->img_ptr,
		&values->bits_per_pixel, &values->size_line, &values->endian);
	mlx_hook(values->win_ptr, 4, 0, mouse_press, values);
	mlx_hook(values->win_ptr, 5, 0, mouse_release, values);
	mlx_hook(values->win_ptr, 6, 0, mouse_move, values);
	mlx_hook(values->win_ptr, 17, 0, close_window, values);
	mlx_hook(values->win_ptr, 2, 0, key_press, values);
	mlx_hook(values->win_ptr, 3, 0, key_release, values);
	mlx_loop_hook(values->mlx_ptr, draw_hook, values);
}

int				main(int ac, char **av)
{
	t_values	*values;

	if (ac < 2)
		ft_die("usage: fdf map [audio.wav]");
	values = ft_memalloc(sizeof(t_values));
	values->wav_file = (ac == 3) ? (av[2]) : (0);
	get_dots(av[1], values);
	set_default(values);
	mlx_initialization(values);
	drawmatrix(values);
	mlx_put_image_to_window(values->mlx_ptr,
		values->win_ptr, values->img_ptr, 0, 0);
	mlx_loop(values->mlx_ptr);
	return (0);
}
