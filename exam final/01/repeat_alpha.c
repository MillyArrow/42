/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 02:49:28 by marrow            #+#    #+#             */
/*   Updated: 2019/08/20 21:17:46 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int count;

	if (ac == 2)
	{
		while(*av[1])
		{
			count = 0;
			if (*av[1] >= 'A' && *av[1] <= 'Z')
				count = *av[1] - 64;
			else if (*av[1] >='a' && *av[1] <= 'z')
				count = *av[1] - 96;
			if (count != 0 )
				while (count-- > 0)
					write(1, av[1], 1);
			else
				write(1, av[1], 1);
			av[1]++;
		}
	}
	write(1, "\n", 1);
	return(0);
}
