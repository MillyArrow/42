/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 23:29:48 by marrow            #+#    #+#             */
/*   Updated: 2020/02/28 09:02:19 by marrow           ###   ########.fr       */
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
	specifier->minus = 0;
	specifier->iszero = 0;
	specifier->len = 0;
}

void         ft_putch(char c, t_spec *spec)
{
    write(1, &c, 1);
    spec->len += 1;
}

void	ft_putstrs(char const *s, t_spec *spec)
{
    if (s)
        while (*s)
            ft_putch(*s++, spec);
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
	while (str[i])
	{
		if (str[i] != '%')
		{
            ft_putchar(str[i++]);
            printed++;
        }
		else
		{
			initialization(specifier);
			ft_format_specifier(str, &i, specifier);
			ft_type(specifier,parameters);
            printed += specifier->len;
		}
	}
	va_end(parameters);
	return (printed);
}


