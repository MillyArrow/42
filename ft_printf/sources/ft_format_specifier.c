/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:13:23 by marrow            #+#    #+#             */
/*   Updated: 2020/02/10 20:36:08 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec			*ft_format_specifier(char *str, size_t *i, t_spec *specifier)
{
	(*i)++;
	ft_set_flag(str, i, specifier);
	ft_set_width(str, i, specifier);
	ft_set_accuracy(str, i, specifier);
	ft_set_length(str, i, specifier);
	if ((str[*i] == 'd' || str[*i] == 'i') && (*i)++)
		specifier->type = 'd';
	if (str[*i] == 'o' && (*i)++)
		specifier->type = 'o';
	if (str[*i] == 'u' && (*i)++)
		specifier->type = 'u';
	if (str[*i] == 'x' && (*i)++)
		specifier->type = 'x';
	if (str[*i] == 'X' && (*i)++)
		specifier->type = 'X';
	if (str[*i] == 'c' && (*i)++)
		specifier->type = 'c';
	if (str[*i] == 's' && (*i)++)
		specifier->type = 's';
	if (str[*i] == 'p' && (*i)++)
		specifier->type = 'p';
	return (specifier);
}

void			ft_set_flag(char *str, size_t *i, t_spec *specifier)
{
	if (str[*i] == '#' && (*i)++)
		specifier->flag = '#';
	if (str[*i] == '0' && (*i)++)
		specifier->flag = '0';
	if (str[*i] == '-' && (*i)++)
		specifier->flag = '-';
	if (str[*i] == '+' && (*i)++)
		specifier->flag = '+';
	if (str[*i] == ' ' && (*i)++)
		specifier->flag = ' ';
}

void			ft_set_width(char *str, size_t *i, t_spec *specifier)
{
	size_t width;

	width = 0;
	if (str[*i] == '*')
	{
		specifier->width = '*';
		return ;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		width = width * 10 + str[*i] - '0';
		(*i)++;
	}
	specifier->width = width;
}

void			ft_set_accuracy(char *str, size_t *i, t_spec *specifier)
{
	size_t accuracy;

	accuracy = 0;
	if (str[*i] == '.' && (*i)++)
	{
		if (str[*i] == '*')
		{
			specifier->accuracy = '*';
			return ;
		}
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			accuracy = accuracy * 10 + str[*i] - '0';
			(*i)++;
		}
		if (accuracy != 0)
		{
			specifier->accuracy = accuracy;
			return ;
		}
		specifier->accuracy = 0;
	}
}

void			ft_set_length(char *str, size_t *i, t_spec *specifier)
{
	if (str[*i] == 'h' && str[*i + 1] != 'h'  && (*i)++)
		specifier->length[0] = 'h';
	if (str[*i] == 'h' && str[*i + 1] == 'h')
	{
		*i += 2;
		specifier->length[0] = 'h';
		specifier->length[1] = 'h';
	}
	if (str[*i] == 'l' && str[*i + 1] != 'l' && (*i)++)
		specifier->length[0] = 'l';
	if (str[*i] == 'l' && str[*i + 1] == 'l')
	{
		*i += 2;
		specifier->length[0] = 'l';
		specifier->length[1] = 'l';
	}
}
