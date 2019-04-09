/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:23:25 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/09 19:26:23 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
#define FDF

#define WIDTH 2000
#define HEIGHT 1500
#define SCALE 50

#include <mlx.h>
#include "libft.h"
#include <stdio.h>
#include <math.h>

typedef struct 		s_dot
{
	int 			z;
	int 			c;
} 					t_dot;

typedef struct 		s_line
{
	double 			x0;
	double 			y0;
	double 			x1;
	double 			y1;
	double			z0;
	double			z1;
	int 			c0;
	int 			c1;
	char 			*data;

} 					t_line;

typedef struct		s_mouse 
{
	int				x;
	int				y;
	int				buttons;
	
}					t_mouse;

typedef struct		s_values
{
	t_mouse			mouse;
	t_dot			**dots;
	int				h;
	int				w;
	char			*data;
				
}					t_values;

void 				drawline(t_line *line);
t_dot				**get_dots(char *file, int *h, int *w);
void 				drawmatrix(char *data, t_dot **dot, int h, int w);
int 				mouse_press(int button, int x, int y, void *param);
int  				mouse_release(int button, int x, int y, void *param);


#endif
