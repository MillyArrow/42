/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plusminus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 01:49:48 by marrow            #+#    #+#             */
/*   Updated: 2019/08/18 05:57:26 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_plusminus(char *str, unsigned int *i)
{
	int result;

	result = ft_muldivred(str, i);
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '+')
		{
			++*i;
			result += ft_muldivred(str, i);
		}
		if (str[*i] == '-')
		{
			++*i;
			result -= ft_muldivred(str, i);
		}
	}
	return (result);
}
