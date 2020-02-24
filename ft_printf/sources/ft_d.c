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
	if (number < 0)
		specifier->minus = 1;
	number = (__int64_t)number;
	return (number);
}

void	    ft_accuracy(t_spec *specifier, int length)
{
	if (length >= (int)specifier->accuracy)
	{
		if (specifier-> minus == 1 && specifier->accuracy != -1 \
		&& specifier->flag[0] != '-')
			ft_putchar('-');
		return;
	}
	length = (int)specifier->accuracy - length;
	if (specifier->minus == 1 && length++ && specifier->flag[0] != '-')
		ft_putchar('-');
	if (specifier->flag[1] == '+' && specifier->flag[0] != '-' &&\
	specifier->minus != 1)
		ft_putchar('+');
	while (length-- > 0)
		ft_putchar('0');
}

void	    ft_width(t_spec *specifier, int length)
{
	int tmp;
	int check;

	tmp = 0;
	check = 0;
	if (specifier->width <= 0)
		return ;
	if (length < (int)specifier->accuracy && specifier->accuracy != -1 && ++tmp)
		length = (int)((int)specifier->width - specifier->accuracy);
	else
		length = (int)(specifier->width - length);
	if ((specifier->flag[1] == '+' && specifier->minus != 1) || \
		(tmp && specifier->minus == 1) || (specifier->flag[2] == ' ' && \
		specifier->flag[1] != '+' && specifier->minus != 1))
		length--;
	if (specifier->minus == 1 && specifier->flag[4] == '0' && specifier->accuracy == -1)
		ft_putchar('-');
	if (specifier->minus != 1 && specifier->flag[4] == '0' \
	&& specifier->flag[1] == '+' && !tmp)
		ft_putchar('+');
	while (length-- > 0)
	{
		if (specifier->flag[4] == '0' && specifier->accuracy == -1)
			ft_putchar('0');
		else
			ft_putchar (' ');
	}
	if (specifier->minus == 1 && specifier->flag[4] != '0' && \
	specifier->flag[0] != '-' && specifier->accuracy == -1)
		ft_putchar('-');
}

void		ft_d(t_spec *specifier, va_list args)
{
	__int64_t 	number;
	int			length;

	number = get_number(specifier,args);
	length = ft_number_length(number);
	if (specifier->flag[0] == '-')
	{
		if (specifier->flag[2] == ' ' && specifier->flag[1] != '+' && \
		specifier->minus != 1)
			ft_putchar(' ');
		if (specifier->minus == 1)
			ft_putchar('-');
		if (specifier->flag[1] == '+' && specifier->minus != 1 && specifier->flag[4] != '0')
			ft_putchar('+');
		ft_accuracy(specifier,length);
		ft_putnbrll(number);;
		ft_width(specifier,length);
		return ;
	}
	if (specifier->flag[2] == ' ' && specifier->flag[1] != '+' && \
		specifier->minus != 1)
		ft_putchar(' ');
	ft_width(specifier,length);
	if (specifier->flag[1] == '+' && specifier->minus != 1 && specifier->flag[4] != '0')
		ft_putchar('+');
	ft_accuracy(specifier,length);
	if (specifier->flag[0] != '-')
	{
		if (specifier->minus == 1 && specifier->accuracy == -1 && !(specifier->width))
			ft_putchar('-');
		ft_putnbrll(number);;
	}
}
