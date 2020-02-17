/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:40:44 by marrow            #+#    #+#             */
/*   Updated: 2020/02/12 06:11:42 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

__int64_t	get_number(t_spec *specifier, va_list args)
{
	__int64_t number;

	number = va_arg(args,__int64_t);
	if (number < 0)
	{
		specifier->minus = 1;
		number *= -1;
	}
	if (ft_strcmp(specifier->length, "hh") == 0)
		number = (signed char)number;
	else if (ft_strcmp(specifier->length, "h") == 0)
		number = (short int)number;
	else if (ft_strcmp(specifier->length, "ll") == 0)
		number = (long long)number;
	else if (ft_strcmp(specifier->length, "l") == 0)
		number = (long)number;
	else
		number = (int)number;
	number = (__int64_t)number;
	return (number);
}

void		ft_d(t_spec *specifier, va_list args)
{
	__int64_t 	number;
	int			length;

	number = get_number(specifier,args);
	length = ft_number_length(number);
	ft_width(specifier,length);
	ft_accuracy(specifier,length);
	ft_putnbrll(number);
}
