/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 03:23:31 by marrow            #+#    #+#             */
/*   Updated: 2020/02/25 03:23:33 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_len_width(t_spec *specifier,int *length, int *tmp)
{
	if ((*length) < (int)specifier->accuracy && specifier->accuracy != -1 && ++(*tmp))
		*length = (int)((int)specifier->width - specifier->accuracy);
	else
		*length = (int)(specifier->width - *length);
	if ((specifier->flag[1] == '+' && specifier->minus != 1) || \
		((*tmp) && specifier->minus == 1) || (specifier->flag[2] == ' ' && \
		specifier->flag[1] != '+' && specifier->minus != 1))
		(*length)--;
	if (specifier->minus == 1 && specifier->flag[4] == '0' \
		&& specifier->accuracy == -1)
		ft_putchar('-');
    if (specifier->flag[3] == '#' && specifier->iszero == 0 \
	&& specifier->accuracy == -1)
        (*length)--;
}

void		ft_width(t_spec *specifier, int length)
{
	int tmp;
	int check;

	tmp = 0;
	check = 1;
	if (specifier->width <= 0)
		return ;
	ft_len_width(specifier, &length, &tmp);
	while (length-- > 0)
	{
		if (specifier->flag[4] == '0' && specifier->accuracy == -1)
		{
			if (specifier->minus != 1 && specifier->flag[4] == '0' \
				&& specifier->flag[1] == '+' && check++ == 1)
				ft_putchar('+');
			ft_putchar('0');
		}
		else
			ft_putchar(' ');
	}
	if (specifier->minus == 1 && specifier->flag[4] != '0' && \
	specifier->flag[0] != '-' && specifier->accuracy == -1)
		ft_putchar('-');
}
