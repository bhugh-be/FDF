/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 23:16:29 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/09 22:02:08 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 		mouse_press(int button, int x, int y, void *param)
{
	t_values 	*values;

	values = (t_values *)param;
	values->mouse.x = x;
	values->mouse.y = y;
	values->mouse.buttons |= 1 << (button - 1);
	
	return (0);
}

int  		mouse_release(int button, int x, int y, void *param)
{
	t_values 	*values;

	values = (t_values *)param;
	values->mouse.x = x;
	values->mouse.y = y;
	values->mouse.buttons &= ~(1 << (button - 1));
	return (0);
}

int  		mouse_move(int x, int y, void *param)
{
	t_values 	*values;

	values = (t_values *)param;
	if (values->mouse.buttons & 1)
	{
		values->dx += x - values->mouse.x;
		values->dy += y - values->mouse.y;
		drawmatrix(values);
		mlx_put_image_to_window(values->mlx_ptr, values->win_ptr, values->img_ptr, 0, 0);
	}
	values->mouse.x = x;
	values->mouse.y = y;
	return (0);	
}
