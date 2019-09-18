/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:22:45 by marrow            #+#    #+#             */
/*   Updated: 2019/08/18 04:13:40 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str, unsigned int *index)
{
	int result;
	int flag;

	result = 0;
	flag = 1;
	if (str[*index] == '-')
	{
		flag = -1;
		++*index;
	}
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		result = result * 10 + (str[*index] - '0');
		++*index;
	}
	return (result * flag);
}
