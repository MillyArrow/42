/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 02:52:47 by marrow            #+#    #+#             */
/*   Updated: 2019/08/22 03:03:51 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int check(char *str,char c,int i)
{
	int j;

	j = 0;
	while(j < i)
	{
		if (str[j] == c)
			return (0);
		++j;
	}
	return (1);
}
int main(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (check(av[1],av[1][i],i) == 1)
				write(1, &av[1][i], 1);
			++i;
		}
		while (av[2][j])
		{
			if(check(av[1],av[2][j],i) && check(av[2],av[2][j],j))
				write(1, &av[2][j], 1);
			++j;
		}
	}
	write(1,"\n",1);
	return (0);
}
