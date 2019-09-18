/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 23:32:34 by marrow            #+#    #+#             */
/*   Updated: 2019/08/22 02:41:29 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char reverse_bits(unsigned char octet)
{
	unsigned char result;
	int i;

	result = 0;
	i = 0;
	while (i < 8)
	{
		result = (result << 1)|(octet & 1);
		octet = octet >> 1;
		i++;
	}
	return (result);
}
unsigned char reverse_bits1(unsigned char octet)
{
	unsigned char result;
	int i;

	result = 0;
	i = 0;
	while (i < 8)
	{
		result = result * 2 + (octet % 2);
		octet = octet / 2;
		i++;
	}
	return (result);
}
int main()
{
	char c = '&';
	c = reverse_bits1(c);
	write(1,&c,1);
	return (0);
}
