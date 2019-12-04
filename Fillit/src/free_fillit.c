/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bashe <bashe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 21:19:55 by bashe             #+#    #+#             */
/*   Updated: 2019/12/01 03:29:31 by bashe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_fillit(t_fillit *head, t_map *map)
{
	int			i;

	i = 0;
	head = free_list(head);
	while (map->size > i)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

t_fillit	*free_list(t_fillit *head)
{
	t_fillit	*next;

	next = NULL;
	while (head != NULL)
	{
		next = head->next;
		ft_memdel((void **)&(head->coordinate));
		ft_memdel((void **)&head);
		head = next;
	}
	return (head);
}
