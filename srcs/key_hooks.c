/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:13:07 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/20 19:13:22 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				key_press(int keycode, void *param)
{
	t_values	*values;

	values = (t_values *)param;
	if (keycode == 53)
		exit(0);
	if (keycode == 35)
	{
		if (!values->stream)
			play(values);
		else if (Pa_IsStreamStopped(values->stream))
			Pa_StartStream(values->stream);
		else
			Pa_StopStream(values->stream);
	}
	return (0);
}

int				key_release(int keycode, void *param)
{
	t_values *values;

	(void)keycode;
	values = (t_values *)param;
	return (0);
}

int				close_window(void *param)
{
	(void)param;
	exit(0);
}
