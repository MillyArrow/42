/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 12:04:18 by eshor             #+#    #+#             */
/*   Updated: 2019/08/11 23:06:51 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_func.h"

int		**create_tab(char **argv)
{
	int **tab;
	int i;
	int j;

	i = 0;
	j = 0;
	tab = (int**)malloc(sizeof(int*) * 9);
	while (i < 9)
	{
		j = 0;
		tab[i] = (int*)malloc(sizeof(int) * 9);
		while (j < 9)
		{
			if (argv[i][j] != '.')
				tab[i][j] = argv[i][j] - '0';
			else
				tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

void	print_tab(int **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putnbr(tab[i][j]);
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		**copy_tab(int **tab)
{
	int i;
	int j;
	int **copy;

	copy = (int**)malloc(sizeof(int*) * 9);
	i = 0;
	j = 0;
	while (i < 9)
	{
		copy[i] = (int*)malloc(sizeof(int) * 9);
		j = 0;
		while (j < 9)
		{
			copy[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
	return (copy);
}
