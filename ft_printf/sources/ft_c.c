/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:29:06 by kcharlet          #+#    #+#             */
/*   Updated: 2020/02/18 17:33:55 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_c(t_spec *specifaer, va_list args)
{
	char	c;
	size_t	i;

	i = 0;
	c = (char)va_arg(args, int);
	if (specifaer->width > 1)
	{
			if (specifaer->flag[0] == '-')
			{
				ft_putchar(c);
				while (i++ < (specifaer->width - 1))
				{
					ft_putchar(' ');
				}
			}
			else
			{
				while (i++ < (specifaer->width - 1))
				{
					ft_putchar(' ');
				}
				ft_putchar(c);
			}
	}
	else
		ft_putchar(c);
}
