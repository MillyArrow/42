/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_numbers_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:10:28 by eshor             #+#    #+#             */
/*   Updated: 2019/08/11 22:39:02 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_func.h"

int		is_in_arr(int nbr, int *arr)
{
	int result;
	int i;

	result = 0;
	i = 0;
	while (i < 9)
	{
		if (nbr == arr[i])
			return (1);
		else
			i++;
	}
	return (0);
}

void	make_lines_columns(int **tab, int *numbers, int line, int column)
{
	int j;
	int counter;

	j = 0;
	counter = 0;
	while (j < 9)
	{
		if (tab[line][j] != 0 && is_in_arr(tab[line][j], numbers) == 0)
		{
			numbers[counter] = tab[line][j];
			counter++;
		}
		if (tab[j][column] != 0 && is_in_arr(tab[j][column], numbers) == 0)
		{
			numbers[counter] = tab[j][column];
			counter++;
		}
		j++;
	}
}

void	make_square(int **tab, int *numbers, int line, int col)
{
	int j;
	int i;
	int counter;

	j = -1;
	counter = 0;
	while (numbers[++j] != 0)
		counter++;
	i = line + 3;
	j = col + 3;
	while (line < i)
	{
		while (col < j)
		{
			if (tab[line][col] != 0 && is_in_arr(tab[line][col], numbers) == 0)
			{
				numbers[counter] = tab[line][col];
				counter++;
			}
			col++;
		}
		col = (col - 1) / 3 * 3;
		line++;
	}
}

int		*make_numbers_arr(int **tab, int line, int column)
{
	int *numbers;
	int j;
	int counter;

	counter = 0;
	numbers = (int*)malloc(sizeof(int) * 9);
	make_lines_columns(tab, numbers, line, column);
	j = 0;
	while (numbers[j] != 0)
	{
		counter++;
		j++;
	}
	line = line / 3 * 3;
	column = column / 3 * 3;
	make_square(tab, numbers, line, column);
	return (numbers);
}
