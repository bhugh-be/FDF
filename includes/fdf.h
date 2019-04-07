/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:23:25 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/06 22:43:11 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
#define FDF

#define WIDTH 2000
#define HEIGHT 1500

# include <mlx.h>
# include "libft.h"
# include <stdio.h>
# include <math.h>

typedef struct		s_dot
{
	int				z;
	int				c;
}					t_dot;

typedef struct			s_line
{
		double			x0;
		double			y0;
		double			x1;
		double			y1;
		int 			c0;
		int 			c1;
		char			*data;

}	

					t_line;

void					drawline(t_line *line);

#endif
