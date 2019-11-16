/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:46:29 by eshor             #+#    #+#             */
/*   Updated: 2019/08/11 22:46:34 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_func.h"

int	err17(int **argv)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] >= 1 && argv[i][j] <= 9)
				count++;
			j++;
		}
		i++;
	}
	if (count < 17)
	{
		return (1);
	}
	return (0);
}

int	check_sym(char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] != '.')
			{
				if (argv[i][j] < '1' || argv[i][j] > '9')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_len(char **argv)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (ft_strlen(argv[i]) != 9)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
