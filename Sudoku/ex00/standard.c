/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:36:55 by eshor             #+#    #+#             */
/*   Updated: 2019/08/11 21:45:30 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_func.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i = i + 1;
	return (i);
}

void	ft_putnbr(int nb)
{
	char c;

	c = '0' + nb;
	ft_putchar(c);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
