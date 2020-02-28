/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:43:59 by marrow            #+#    #+#             */
/*   Updated: 2020/02/27 21:00:09 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_type(t_spec *specifier, va_list args)
{
	if (specifier->type == 'd')
		ft_d(specifier, args);
	if (specifier->type == 'c')
		ft_c(specifier, args);
	if (specifier->type == 's')
		ft_s(specifier, args);
	if (specifier->type == 'p')
		ft_p(specifier, args);
	if (specifier->type == 'o')
		ft_o(specifier, args);
	if (specifier->type == 'u')
		ft_u(specifier, args);
	if (specifier->type == 'x')
		ft_x(specifier, args);
	if (specifier->type == 'X')
		ft_big_X(specifier, args);
	if (specifier->type == '%')
		ft_pct(specifier);
}
