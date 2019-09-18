/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 23:56:31 by marrow            #+#    #+#             */
/*   Updated: 2019/08/21 20:27:26 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char 	*ft_strdup(char *src)
{
	int i ;

	i = 0;
	char *c;
	if (!(c = (char *)malloc(sizeof(src) + sizeof(char))))
		return (NULL);
	while (src[i])
		i++;
	c[i] = '\0';
	while (i >= 0)
	{
		c[i] = src[i];
		i--;
	}
	return (c);
}
int main(void)
{
	char a[] = "privet !";
	char *b =(char *)malloc(sizeof(a) + sizeof(char));
	b = ft_strdup(a);
	printf("%s", b);
	return(0);
}
