/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_and_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:26:12 by eshor             #+#    #+#             */
/*   Updated: 2019/08/11 21:25:59 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_func.h"

int		*index_first_zero(int **tab)
{
	int i;
	int j;
	int *row_and_column;

	i = 0;
	j = 0;
	row_and_column = (int*)malloc(sizeof(int) * 2);
	row_and_column[0] = -1;
	row_and_column[1] = -1;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (tab[i][j] == 0)
			{
				row_and_column[0] = i;
				row_and_column[1] = j;
				return (row_and_column);
			}
			j++;
		}
		i++;
	}
	return (row_and_column);
}

int		*index_last_zero(int **tab)
{
	int i;
	int j;
	int *row_and_column;

	i = 8;
	j = 8;
	row_and_column = (int*)malloc(sizeof(int) * 2);
	row_and_column[0] = -1;
	row_and_column[1] = -1;
	while (i >= 0)
	{
		j = 0;
		while (j >= 0)
		{
			if (tab[i][j] == 0)
			{
				row_and_column[0] = i;
				row_and_column[1] = j;
				return (row_and_column);
			}
			j++;
		}
		i++;
	}
	return (row_and_column);
}

int		compare(int **tab, int **reverse_tab)
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
			if (tab[i][j] == reverse_tab[i][j])
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int		solve(int **tab)
{
	int *numbers;
	int *options;
	int n;
	int *row_and_column;

	if (is_full(tab) == 1)
		return (1);
	row_and_column = index_first_zero(tab);
	numbers = make_numbers_arr(tab, row_and_column[0], row_and_column[1]);
	options = make_options_arr(numbers);
	n = 0;
	while (n < 9 && options[n] != 0)
	{
		tab[row_and_column[0]][row_and_column[1]] = options[n];
		if (solve(tab) == 1)
			return (1);
		tab[row_and_column[0]][row_and_column[1]] = 0;
		n++;
	}
	return (0);
}

int		solve_reverse(int **tab)
{
	int *numbers;
	int *options;
	int n;
	int *row_and_column;

	if (is_full(tab) == 1)
		return (1);
	row_and_column = index_last_zero(tab);
	numbers = make_numbers_arr(tab, row_and_column[0], row_and_column[1]);
	options = make_options_arr(numbers);
	n = 0;
	while (n < 9 && options[n] != 0)
	{
		tab[row_and_column[0]][row_and_column[1]] = options[n];
		if (solve(tab) == 1)
			return (1);
		tab[row_and_column[0]][row_and_column[1]] = 0;
		n++;
	}
	return (0);
}
