/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:03:10 by marrow            #+#    #+#             */
/*   Updated: 2020/03/03 21:03:13 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t         ft_l_num(long double number)
{
    int i;

    i = 0;
    while (number >= 1)
    {
        number /= 10;
        i++;
    }
    return (i);
}

long double	ft_real_part(t_spec *specifier, long double number)
{
	__int128_t	t_number;
	__int128_t  t2_number;
	size_t		prec;
	size_t      l_num;
	char        check;

	t_number = 0;
	check = 0;
	prec = specifier->accuracy + 1;
	while (prec)
	{
		number *= 10;
		t_number = number;
		t2_number = number * 10;
		if (t_number == 0 && prec != 1 && (t2_number != 9) && ++check)
		{
			ft_putch('0', specifier);
			specifier->accuracy--;
		}
		prec--;
	}
	l_num = ft_l_num(number / 10);
	if (t_number % 10 >= 5)
	{
		number = number / 10 + 1;
		if (l_num && l_num != (ft_l_num(number)) && !check)
		{
			number--;
			t_number /= 10;
			while ((t_number % 10) == 9)
			{
				ft_putch('0', specifier);
				specifier->accuracy--;
				t_number /= 10;
			}
		}
	}
	return (number);
}

void     ft_round(t_spec *specifier, long double number)
{
	__int128_t      temp;
	__int128_t      temp2;
	size_t          prec;
	size_t          l_num;
	char            check;

	check = 0;
	temp = number;
	number = number - temp;
	prec = specifier->accuracy + 1;
	while (prec)
	{
		number *= 10;
		temp = number;
		temp2 = number * 10;
		if (temp == 0 && prec != 1 && (temp2 != 9))
			++check;
		prec--;
	}
	temp = number;
	l_num = ft_l_num(number / 10);
	if (temp % 10 >= 5)
		number = number / 10 + 1;
	else
		number /= 10;
	if (l_num && l_num != (ft_l_num(number)) && !check)
		specifier->int_part++;
}

void		ft_f_precision(t_spec *specifier, long double number)
{
	__int128_t		int_number;
	int				start;

	int_number = number;
	start = 0;
	number = ft_real_part(specifier, number - int_number);
	while (number >= 1)
		number /= 10;
	while (specifier->accuracy != -1 && specifier->accuracy--)
	{
		number *= 10;
		if (start != 0)
			number = number - int_number * 10;
		int_number = number;
		ft_putch(int_number + '0', specifier);
		start++;
	}
}

void		ft_putnbr_f(t_spec *specifier, long double number, size_t int_part)
{
	__int128_t  temp;
	long double t_number;
	char        start;

	temp = 0;
	start = 0;
	int_part = 0;
	t_number = number;
	if (!(temp = t_number))
	{
		specifier->width--;
		ft_putch('0',specifier);
	}
	if (temp)
		ft_putnbrs_u(specifier->int_part,10, specifier);
	if (specifier->accuracy != 0 || specifier->flag[3] == '#')
		ft_putch('.', specifier);
}

void		display_f(t_spec *specifier, long double number, size_t int_part)
{
	if (specifier->flag[2] == ' ' && specifier->flag[1] != '+' && \
		specifier->minus != 1 && ++specifier->len_f)
		ft_putch(' ', specifier);
	if (specifier->minus == 1)
		specifier->len_f++;
	ft_width_f(specifier);
	if (specifier->flag[1] == '+' && specifier->minus != 1 && \
	specifier->flag[4] != '0')
		ft_putch('+', specifier);
	if (specifier->accuracy == 0 && number == 0)
		return ;
	if (specifier->flag[0] != '-')
	{
		if (specifier->minus == 1 && specifier->width == 0)
			ft_putch('-', specifier);
		ft_putnbr_f(specifier, number, int_part);
		ft_f_precision(specifier,number);
	}
}

void	ft_width_f(t_spec *specifier)
{
	if (specifier->flag[1] == '+' && specifier->minus != 1 && \
	specifier->flag[4] != '0' && specifier->plus++ == 0)
		specifier->len_f++;
	if (specifier->minus == 1 && specifier->flag[4] == '0' \
		&& specifier->flag[0] != '-')
		ft_putch('-', specifier);
	if (specifier->len_f >= specifier->width && specifier->minus != 1 \
	&& specifier->flag[4] == '0' && specifier->flag[1] == '+' && \
	specifier->plus++ == 0 && ++specifier->len_f)
		ft_putch('+', specifier);
	while (specifier->len_f < specifier->width)
	{
		if (specifier->flag[4] == '0' && specifier->flag[0] != '-' \
		&& specifier->inf_nan == 0)
		{
			if (specifier->minus != 1 && specifier->flag[4] == '0' \
				&& specifier->flag[1] == '+' && specifier->plus++ == 0 && ++specifier->len_f)
				ft_putch('+', specifier);
			ft_putch('0', specifier);
		}
		else
			ft_putch(' ', specifier);
		specifier->width--;
	}
	if (specifier->minus == 1 && specifier->flag[4] != '0' && \
	specifier->flag[0] != '-' && specifier->width != 0)
		ft_putch('-', specifier);
}

void		ft_f(t_spec *specifier, va_list args)
{
    long double number;
    size_t		l_int_part;

    number = 0;
    if (specifier->length[0] == 'l' || specifier->length[0] == '\0')
        number = (double)va_arg(args, double);
    else if (specifier->length[0] == 'L')
        number = (long double)va_arg(args, long double);
    if (number == 1.0 / 0.0 && ++specifier->inf_nan)
    {
	    specifier->len_f = 3;
	    ft_width_f(specifier);
	    ft_putstr("inf");
	    return ;
    }
	if (number == -1.0 / 0.0 && ++specifier->inf_nan)
	{
		specifier->len_f = 4;
		ft_width_f(specifier);
		ft_putstr("-inf");
		return ;
	}
	if (number != number && ++specifier->inf_nan)
	{
		specifier->len_f = 3;
		ft_width_f(specifier);
		ft_putstr("nan");
		return ;
	}
	if (specifier->accuracy == -1)
		specifier->accuracy = 6;
	if (number < 0 && (number *= -1))
		specifier->minus = 1;
	specifier->int_part = number;
	l_int_part = ft_l_num(number);
	specifier->len_f = l_int_part + specifier->accuracy;
	if (specifier->accuracy != 0 || specifier->flag[3] == '#')
		specifier->len_f++;
	ft_round(specifier, number);
	if (specifier->flag[0] == '-')
	{
		if (specifier->flag[2] == ' ' && specifier->flag[1] != '+' && \
		specifier->minus != 1 && ++specifier->len_f)
			ft_putch(' ', specifier);
		if (specifier->minus == 1 && ++specifier->len_f)
			ft_putch('-', specifier);
		if (specifier->flag[1] == '+' && specifier->minus != 1 \
			&& specifier->plus++ == 0 && ++specifier->len_f)
			ft_putch('+', specifier);
		ft_putnbr_f(specifier, number, l_int_part);
		ft_f_precision(specifier,number);
		ft_width_f(specifier);
		return ;
	}
	display_f(specifier, number, l_int_part);
}
