/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:53:15 by eshor             #+#    #+#             */
/*   Updated: 2019/08/11 23:20:25 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_func.h"

int	main(int argc, char **argv)
{
	int **t;
	int **tab_copy;

	if (argc == 10)
	{
		argv++;
		t = create_tab(argv);
		if (!check_len(argv) && !check_sym(argv) && !check_tab(t) && !err17(t))
		{
			tab_copy = copy_tab(t);
			if (solve(t) == 1)
			{
				solve_reverse(tab_copy);
				if (compare(t, tab_copy) == 1)
				{
					print_tab(t);
					return (0);
				}
			}
		}
	}
	write(1, "Error\n", 6);
	return (0);
}
