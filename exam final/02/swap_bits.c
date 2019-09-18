/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 02:43:27 by marrow            #+#    #+#             */
/*   Updated: 2019/08/22 02:47:09 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
unsigned char swap_bits(unsigned char octet)
{
	return((octet >> 4)|(octet << 4));
}
int main()
{
	char c = '&';
	c = swap_bits(c);
	write(1,&c,1);
	return (0);
}
