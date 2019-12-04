/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bashe <bashe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:23:27 by bashe             #+#    #+#             */
/*   Updated: 2019/12/01 03:27:15 by bashe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*get_figure(char *line, t_fillit *head, char set)
{
	int xmin;
	int xmax;
	int ymax;
	int i;

	xmin = 3;
	ymax = 0;
	xmax = 0;
	i = 0;
	get_xmin(line, &xmin);
	get_coordinate(line, head, &xmin);
	while (i <= 4)
	{
		if (head->coordinate->x[i] > xmax)
			xmax = head->coordinate->x[i];
		if (head->coordinate->y[i] > ymax)
			ymax = head->coordinate->y[i];
		i++;
	}
	head->width = xmax + 1;
	head->height = ymax + 1;
	head->character = set;
	return (head);
}

void		get_coordinate(char *line, t_fillit *head, int *xmin)
{
	int x;
	int y;
	int i;
	int j;

	x = 0;
	i = 0;
	j = 0;
	y = 0;
	while (*line != '\0')
	{
		while (*line == '.' && line++)
			x++;
		if (*line == '#')
		{
			while (*line == '#' && line++)
			{
				head->coordinate->x[i++] = x++ - *xmin;
				head->coordinate->y[j++] = y;
			}
			y++;
		}
		if (*line == '\n' && line++)
			x = 0;
	}
}

void		get_xmin(char *line, int *xmin)
{
	int x;
	int i;

	x = 0;
	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] == '.' && ++i)
			x++;
		if (line[i] == '#' && ++i)
		{
			if (*xmin > x)
				*xmin = x;
		}
		if (line[i] == '\n' && ++i)
			x = 0;
	}
}

t_fillit	*read_figure(char *line, t_fillit *head, int *i)
{
	int			ret;
	char		set;
	char		*str;

	ret = 0;
	set = 'A';
	str = NULL;
	if (validation(line) == 0)
		error(head);
	else
	{
		while ((str = ft_strsub(line, ret, 21)) && *str != '\0')
		{
			str[20] = '\0';
			head = new_node(head);
			head = get_figure(str, head, set);
			ft_memdel((void **)&str);
			set++;
			ret += 21;
			(*i)++;
		}
		ft_memdel((void **)&str);
		ft_list_reverse(&head);
	}
	return (head);
}

int			ft_sqrt(int a)
{
	float	x;
	int		i;

	x = 1.0;
	i = 0;
	while (x * x < a)
		x *= 10;
	while (i < 10)
	{
		x = x + a / x;
		x = x / 2;
		i++;
	}
	return (x);
}
