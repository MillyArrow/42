/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 02:01:18 by marrow            #+#    #+#             */
/*   Updated: 2019/08/18 05:57:38 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_factor(char *str, unsigned int *i)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		++*i;
	}
	if (str[*i] == '(')
	{
		++*i;
		result = ft_plusminus(str, i);
		++*i;
	}
	else
		result = ft_atoi(str, i);
	return (sign * result);
}
