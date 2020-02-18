/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accuracy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 23:28:56 by marrow            #+#    #+#             */
/*   Updated: 2020/02/18 17:49:56 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	    	ft_accuracy(t_spec *specifier, int length)
{
	if (length >= (int)specifier->accuracy)
		return ;
	length = (int)specifier->accuracy - length;
	while (length-- > 0)
		ft_putchar('0');
}
