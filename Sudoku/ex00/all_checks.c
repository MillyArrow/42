/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:26:03 by bedavis           #+#    #+#             */
/*   Updated: 2019/08/11 22:09:53 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_func.h"

int		check_rep_square(int **tab, int x, int y)
{
	int line;
	int column;
	int i;
	int j;

	line = x / 3 * 3;
	column = y / 3 * 3;
	i = line + 3;
	j = column + 3;
	while (line < i)
	{
		while (column < j)
		{
			if (tab[line][column] == tab[x][y] && !(line == x && column == y))
				return (0);
			column++;
		}
		column = (column - 1) / 3 * 3;
		line++;
	}
	return (1);
}

int		check_rep_landc(int **tab, int x, int y)
{
	int j;

	j = 0;
	while (++j < 9)
	{
		if (tab[x][y] == tab[x][j] && j != y)
			return (0);
		if (tab[x][y] == tab[j][y] && j != x)
			return (0);
	}
	return (1);
}

int		check_elem(int **tab)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	j = -1;
	x = -1;
	y = -1;
	while (++x < 9)
	{
		y = 0;
		while (++y < 9)
		{
			if (tab[x][y] != 0)
			{
				if (check_rep_square(tab, x, y) == 0 ||
					check_rep_landc(tab, x, y) == 0)
					return (0);
			}
		}
	}
	return (1);
}

int		check_tab(int **tab)
{
	if (!check_elem(tab))
	{
		return (1);
	}
	return (0);
}
