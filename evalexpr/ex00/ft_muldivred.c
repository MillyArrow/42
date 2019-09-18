/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_muldivred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 01:54:53 by marrow            #+#    #+#             */
/*   Updated: 2019/08/18 05:57:18 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_muldivred(char *str, unsigned int *i)
{
	int result;

	result = ft_factor(str, i);
	while (str[*i] == '*' || str[*i] == '/' || str[*i] == '%')
	{
		if (str[*i] == '*')
		{
			++*i;
			result *= ft_factor(str, i);
		}
		if (str[*i] == '/')
		{
			++*i;
			result /= ft_factor(str, i);
		}
		if (str[*i] == '%')
		{
			++*i;
			result %= ft_factor(str, i);
		}
	}
	return (result);
}
