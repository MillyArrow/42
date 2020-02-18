/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 23:30:10 by marrow            #+#    #+#             */
/*   Updated: 2020/02/18 20:23:04 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	    ft_width(t_spec *specifier, int length)
{

	if (specifier->width <= 0)
		return ;
	if ((int)specifier->width < specifier->accuracy)
		length = (int)((int)specifier->width - specifier->accuracy);
	else
		length = (int)(specifier->width - length);
	while (length-- > 0)
	{
		if (specifier->flag == '0')
			ft_putchar('0');
		else
			ft_putchar (' ');
	}
}
