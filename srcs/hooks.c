/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 23:16:29 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/16 16:02:36 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int mouse_press(int button, int x, int y, void *param)
{
	t_values *values;

	values = (t_values *)param;
	values->mouse.x = x;
	values->mouse.y = y;
	if (button == 1 || button == 2)
		values->mouse.buttons |= 1 << (button - 1);
	if (button == 4)
	{
		values->scale += (values->scale > 100000000) ? (0) : (2);
		drawmatrix(values);
		mlx_clear_window(values->mlx_ptr, values->win_ptr);
		mlx_put_image_to_window(values->mlx_ptr, values->win_ptr, values->img_ptr, 0, 0);
	}
	if (button == 5)
	{
		values->scale -= (values->scale < 1) ? (0) : (2);
		drawmatrix(values);
		mlx_clear_window(values->mlx_ptr, values->win_ptr);
		mlx_put_image_to_window(values->mlx_ptr, values->win_ptr, values->img_ptr, 0, 0);
	}
	if (button == 3)
	{
		set_default(values);
		drawmatrix(values);
		mlx_clear_window(values->mlx_ptr, values->win_ptr);
		mlx_put_image_to_window(values->mlx_ptr, values->win_ptr, values->img_ptr, 0, 0);
	}
	return (0);
}

int mouse_release(int button, int x, int y, void *param)
{
	t_values *values;

	values = (t_values *)param;
	values->mouse.x = x;
	values->mouse.y = y;
	values->mouse.buttons &= ~(1 << (button - 1));
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	t_values *values;

	values = (t_values *)param;
	if (values->mouse.buttons & 2)
	{
		values->offx += x - values->mouse.x;
		values->offy += y - values->mouse.y;
		drawmatrix(values);
		mlx_clear_window(values->mlx_ptr, values->win_ptr);
		mlx_put_image_to_window(values->mlx_ptr, values->win_ptr, values->img_ptr, 0, 0);
	}
	else if (values->mouse.buttons & 1)
	{
		values->dx += x - values->mouse.x;
		values->dy += y - values->mouse.y;
		drawmatrix(values);
		mlx_clear_window(values->mlx_ptr, values->win_ptr);
		mlx_put_image_to_window(values->mlx_ptr, values->win_ptr, values->img_ptr, 0, 0);
	}
	values->mouse.x = x;
	values->mouse.y = y;
	return (0);
}

int key_press(int keycode, void *param)
{
	t_values *values;

	values = (t_values *)param;
	if (keycode == 53)
		exit(0);
	// if (keycode == 4)
	// ;
	return (0);
}

int key_release(int keycode, void *param)
{
	(void)keycode;
	t_values *values;
	values = (t_values *)param;
	return (0);
}

int close_window(void *param)
{
	(void)param;
	exit(0);
}