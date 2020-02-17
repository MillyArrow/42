/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accuracy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 23:28:56 by marrow            #+#    #+#             */
/*   Updated: 2020/02/12 14:24:27 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	    	ft_accuracy(t_spec *specifier, size_t length)
{
	if (length >= specifier->accuracy)
		return ;
	length = specifier->accuracy - length;
	while (length-- > 0)
		ft_putchar('0');
}
