/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 23:37:13 by marrow            #+#    #+#             */
/*   Updated: 2019/08/20 23:55:42 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *c)
{
	unsigned int number;
	int sign;

	sign = 1;
	number = 0;
	while (*c == 32 || (*c >= 9 && *c <= 13))
		c++;
	if (*c == '-')
	{
		sign = -1;
		c++;
	}
	else if (*c == '+')
		c++;
	while (*c >= '0' && *c <= '9')
	{
		number = number * 10 + *c - '0';
		c++;
	}
	return (sign * number);
}
int	main(void)
{
	char c[]= "    \n\n\v\f\r\t -5234AAAgreghrsth";
	printf("%d",ft_atoi(c));
	return (0);
}
