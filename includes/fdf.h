/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:23:25 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/05 18:23:27 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
#define FDF

# include <mlx.h>
# include "libft.h"
# include <stdio.h>
# include <math.h>

// typedef struct		s_pixel
// {
// 	void			*win_ptr;
// 	void 			*mlx_ptr;
// 	int				x;
// 	int				y;
// 	int				c;
// }					t_pixel;

typedef struct			s_line
{
		double			x0;
		double			y0;
		double			x1;
		double			y1;
		int 			c0;
		int 			c1;
		void			*win;
		void			*mlx;

}						t_line;

void					drawline(t_line *line);

#endif
