/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 23:16:29 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/09 19:23:14 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 		mouse_press(int button, int x, int y, void *param)
{
	t_values 	*values;

	values = (t_values *)param;
	values->mouse.buttons |= 1 << button - 1;
	
	return (0);
}

int  		mouse_release(int button, int x, int y, void *param)
{
	t_values 	*values;

	values = (t_values *)param;
	values->mouse.buttons &= ~(1 << button - 1);
	return (0);
}

int  		mouse_move(int x, int y, void *param)
{
	t_values 	*values;

	values = (t_values *)param;
	if (values->mouse.buttons & 1)
		rotate();
	values->mouse.x = x;
	values->mouse.y = y;
	return (0);	
}
