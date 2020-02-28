/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:27:11 by marrow            #+#    #+#             */
/*   Updated: 2020/02/28 09:00:00 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_s(t_spec *specifaer, va_list args)
{
	char	*length;
	size_t	len;
	size_t	i;

	i = 0;
	length = (char *)va_arg(args, char*);
	if (length == NULL)
		length = "(null)";
	len = ft_strlen(length);
	if (specifaer->accuracy != -1 && (size_t)specifaer->accuracy < len)
	{
		len = specifaer->accuracy;
		length = ft_strsub(length, 0, len);
	}
	if (specifaer->width > len)
	{
		if (specifaer->flag[0] == '-')
		{
			ft_putstrs(length, specifaer);
			while (i++ < (specifaer->width - len))
				ft_putch(' ', specifaer);
			return ;
		}
		else
		{
			while (i++ < (specifaer->width - len))
				ft_putch(' ', specifaer);
			ft_putstrs(length, specifaer);
			return ;
		}
	}
	ft_putstrs(length, specifaer);
}