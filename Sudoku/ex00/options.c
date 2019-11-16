/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:12:27 by eshor             #+#    #+#             */
/*   Updated: 2019/08/11 22:39:21 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_func.h"

int		*make_options_arr(int *numbers)
{
	int i;
	int *options;
	int k;

	options = (int*)malloc(sizeof(int) * 9);
	i = 1;
	k = 0;
	while (i < 10)
	{
		if (is_in_arr(i, numbers) == 0)
		{
			options[k] = i;
			k++;
		}
		i++;
	}
	return (options);
}

int		is_single(int *numbers)
{
	int i;
	int count_zero;
	int j;

	count_zero = 0;
	i = 0;
	if (numbers[7] == 0)
		return (0);
	else
	{
		return (1);
	}
	return (j);
}
