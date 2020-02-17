/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:43:59 by marrow            #+#    #+#             */
/*   Updated: 2020/02/12 13:45:15 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_type(t_spec *specifier, va_list args)
{
	if (specifier->type == 'd')
		ft_d(specifier, args);
	if (specifier->type == 'c')
		ft_c(specifier, args);
}
