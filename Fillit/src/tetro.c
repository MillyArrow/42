/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bashe <bashe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 09:23:01 by marrow            #+#    #+#             */
/*   Updated: 2019/12/01 04:05:57 by bashe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*create(void)
{
	t_fillit	*new_elem;

	new_elem = (t_fillit *)ft_memalloc(sizeof(t_fillit));
	new_elem->coordinate = (t_point *)ft_memalloc((sizeof(t_point) * 4));
	new_elem->next = NULL;
	return (new_elem);
}

t_fillit	*new_node(t_fillit *head)
{
	t_fillit	*tmp;

	tmp = head;
	if (head == NULL)
		head = create();
	else
	{
		tmp = create();
		tmp->next = head;
		head = tmp;
	}
	return (head);
}

void		ft_list_reverse(t_fillit **head)
{
	t_fillit	*prev;
	t_fillit	*next;
	t_fillit	*curr;

	prev = 0;
	next = 0;
	curr = *head;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}
