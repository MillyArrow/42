/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 03:18:18 by marrow            #+#    #+#             */
/*   Updated: 2019/08/20 04:43:52 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
void ft_putstr(char *s1)
{
	while (*s1)
		write(1, s1++, 1);
}
int	main(void)
{
	int i = 0;
	char s1[] = "privet";
	char s2[] = "aloha1sad";
	while (s1[i])
	{
		write(1, &s1[i], 1);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	while (s2[i])
	{
		write(1, &s2[i], 1);
		i++;
	}
	write(1, "\n",1);
	ft_putstr(ft_strcpy(s1,s2));
	write(1, "\n",1);
	return (0);
}
