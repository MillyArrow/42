/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 09:17:38 by marrow            #+#    #+#             */
/*   Updated: 2019/11/17 18:17:11 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		validation(char *line)
{
	int i;
	int l;
	int sh;

	i = 0;
	l = 0;
	sh = 0;
	if (!line)
		return (0);
	while(line[i] != '\0')
	{
		if (!validString(line, &i, &sh))
			return (0);
		l++;
		if (line[i + 1] == '\n' && l != 4)
			return (0);
		if (l == 4 && line[i + 1] == '\n')
		{
			i += 2;
			l = 0;
			sh = 0;
		}
		i++;
	}
	return (1);
}
int		validString(char *line, int *i, int *sh)
{
	while (line[*i] != '\n')
	{
		if (line[*i] == '#')
		{
			if (line[*i + 1] != '#' && line[*i - 1] != '#' && line[*i + 5] != '#' && line[*i - 5] != '#') // not right
				return (0);
			(*sh)++;
		}
		if ((line[*i] != '#' && line[*i] != '.') || *sh != 4) // sh kolichestvo #
			return(0);
		(*i)++;
	}
	return (1);
}
