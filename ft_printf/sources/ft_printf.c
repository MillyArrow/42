/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 23:29:48 by marrow            #+#    #+#             */
/*   Updated: 2020/02/12 14:55:50 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		initialization(t_spec *specifier)
{
	ft_bzero(specifier->flag, sizeof(char) * 5);
	specifier->width = 0;
	specifier->accuracy = 0;
	ft_bzero(specifier->length, 3);
	specifier->type = 0;
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	parameters;
	size_t	printed;
	char	*str;
	t_spec	*specifier;
	size_t	i;

	str = (char*)format;
	printed = 0;
	specifier = NULL;
	va_start(parameters, format);
	i = 0;
	specifier = (t_spec*)ft_memalloc(sizeof(t_spec));
	initialization(specifier);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i++]);
		else 
		{
			ft_format_specifier(str, &i, specifier);
			ft_type(specifier,parameters);
		}
		printed++;
	}
	va_end(parameters);
	return (printed);
}


