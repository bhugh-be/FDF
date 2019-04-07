/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:16:24 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/07 06:15:44 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot       get_t_dot(char *s)
{
    t_dot   dot;

    dot.z = ft_atoi(s);
    dot.c = 0xffffff;
    while (ft_isdigit(*s))
        s++;
    if (!*s)
        return (dot);
    s += 3;
    dot.c = ft_atoi_base(s, 16);
    return (dot);
}

int         dot_validation(char *str)
{
	while (*str >= '0' && *str <= '9') 
		str++;
	if (*str == 0)
		return (1);
	if (*str++ != ',')
		return (ft_die("map is huita"));
	if (*str++ != '0')
		return (ft_die("map is huita"));
	if (*str++ != 'x')
		return (ft_die("map is huita"));
	while ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f') || (*str >= 'A' && *str <= 'F'))
		str++;
	if (*str == 0)
		return (1);
	return (ft_die("map is huita"));
}

t_list         *get_list(char *file)
{
	int     fd;
	char    *line;
	t_list  *begin;
	int     count;
	char     **str;

	fd = open(file, O_RDONLY);
	begin = NULL;
	get_next_line(fd, &line);
	count = ft_vector_len(str = ft_strsplit(line, ' '));
	ft_list_add(&begin, (void *)str);
	while (get_next_line(fd, &line) == 1)
	{
		if (count != ft_vector_len(str = ft_strsplit(line, ' ')))
			return ((t_list*)ft_die("map is huita"));
		ft_list_add(&begin, (void *)str);
		free(line);
	}
	return (begin);
}

t_dot       **get_dots(char *file, int *w, int *h)
{
	t_dot   **dots;
	t_list  *list;
	t_list  *tmp;
	int     y;
	int     x;
    char    **line;

	*h = ft_list_count(list = get_list(file));
	*w = ft_vector_len((char **)list->data);
	dots = (t_dot**)malloc(sizeof(t_dot*) * *h);
	y = 0;
	while (list)
	{
		dots[y] = (t_dot*)malloc(sizeof(t_dot) * *w);
        x = 0;
        line = (char **)list->data;
		while (line[x])
        {
            dots[y][x] = get_t_dot(line[x]);
            x++;
        }
        list = list->next;
		y++;
	}
    return (dots);
}

int         main(int ac, char ** av)
{
	(void)ac;
    int     h;
    int     w;
    t_dot   **dot;

	dot = get_dots(av[1], &h, &w);
    for (int j = 0; j < w; j++)
    {
        for (int i = 0; i < h; i++)
            printf("%3d,0x%x", dot[j][i].z, (unsigned)dot[j][i].c);
        printf("\n");
    }
    
    printf ("%d\n%d\n", h, w);
    return (0);
	}
