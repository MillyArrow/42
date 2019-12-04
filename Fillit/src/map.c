/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:53:00 by bashe             #+#    #+#             */
/*   Updated: 2019/11/30 19:21:50 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*map_create(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->array[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void		map_print(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

void		free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&(map));
}

void		map_clean(t_map *map, t_fillit *head, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < head->height)
	{
		i = 0;
		while (i < head->width)
		{
			map->array[head->coordinate->y[0] + y]\
			[head->coordinate->x[0] + x] = '.';
			map->array[head->coordinate->y[1] + y]\
			[head->coordinate->x[1] + x] = '.';
			map->array[head->coordinate->y[2] + y]\
			[head->coordinate->x[2] + x] = '.';
			map->array[head->coordinate->y[3] + y]\
			[head->coordinate->x[3] + x] = '.';
			i++;
		}
		j++;
	}
}
