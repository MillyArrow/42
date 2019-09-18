/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 04:53:50 by marrow            #+#    #+#             */
/*   Updated: 2019/08/18 05:48:45 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

char	*ft_delete_spaces(char *str)
{
	int		i;
	int		j;
	char	*a;

	a = (char *)malloc(sizeof(char *) * (ft_strlen_w_s(str)));
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			a[j++] = str[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
