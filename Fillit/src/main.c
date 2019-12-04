/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 19:16:48 by marrow            #+#    #+#             */
/*   Updated: 2019/12/02 20:50:46 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int			i;
	char		line[700];
	int			ret;
	t_fillit	*head;
	t_map		*map;

	i = 0;
	head = NULL;
	if (ac != 2)
		ft_putstr("usage: fillit input_file\n");
	else
	{
		ret = read(open(av[1], O_RDONLY), line, 700);
		line[ret] = '\0';
		head = read_figure(line, head, &i);
		if (i < 1 || i > 26)
			error(head);
		map = solve(head, &i);
		map_print(map);
		free_fillit(head, map);
	}
	return (0);
}
