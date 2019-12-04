/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 04:34:50 by marrow            #+#    #+#             */
/*   Updated: 2019/11/30 19:34:47 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			solve_map(t_map *map, t_fillit *head)
{
	int x;
	int y;

	if (head == NULL)
		return (1);
	y = 0;
	while (y <= map->size - head->height)
	{
		x = 0;
		while (x <= map->size - head->width)
		{
			if (check_dot(map, head, x, y))
			{
				place_tetro(map, head, x, y);
				if (solve_map(map, head->next))
					return (1);
				else
					map_clean(map, head, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void		place_tetro(t_map *map, t_fillit *head, int x, int y)
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
			[head->coordinate->x[0] + x] = head->character;
			map->array[head->coordinate->y[1] + y]\
			[head->coordinate->x[1] + x] = head->character;
			map->array[head->coordinate->y[2] + y]\
			[head->coordinate->x[2] + x] = head->character;
			map->array[head->coordinate->y[3] + y]\
			[head->coordinate->x[3] + x] = head->character;
			i++;
		}
		j++;
	}
}

t_map		*solve(t_fillit *head, int *i)
{
	t_map	*map;
	int		size;

	size = ft_sqrt(4 * (*i));
	map = map_create(size);
	while (!solve_map(map, head))
	{
		size++;
		free_map(map);
		map = map_create(size);
	}
	return (map);
}

int			check_dot(t_map *map, t_fillit *head, int x, int y)
{
	if (map->array[y + head->coordinate->y[0]]\
		[x + head->coordinate->x[0]] == '.' &&
		map->array[y + head->coordinate->y[1]]\
		[x + head->coordinate->x[1]] == '.' &&
		map->array[y + head->coordinate->y[2]]\
		[x + head->coordinate->x[2]] == '.' &&
		map->array[y + head->coordinate->y[3]]\
		[x + head->coordinate->x[3]] == '.')
		return (1);
	return (0);
}
