/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 09:17:38 by marrow            #+#    #+#             */
/*   Updated: 2019/11/21 22:13:06 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		g_t;

int		validation(char *line)
{
	int i;
	int l;
	int sh;

	i = 0;
	l = 0;
	sh = 0;
	if (valid_file(line, &i, &l, &sh) == 0)
		return (0);
	return (1);
}

int		valid_file(char *line, int *i, int *l, int *sh)
{
	if (!line || !(*line))
		return (0);
	while (line[*i] != '\0')
	{
		(*l)++;
		if (!valid_string(line, &*i, &*sh, &*l))
			return (0);
		if ((line[*i + 1] == '\n' || line[*i + 1] == '\0') && *l != 4)
			return (0);
		if (valid_tetro(line, &*l, &*sh, &*i) == 0)
			return (0);
		if (line[*i] != '\0')
			(*i)++;
	}
	if (line[*i - 2] != '#' && line[*i - 2] != '.')
		return (0);
	return (1);
}

int		valid_string(char *line, int *i, int *sh, int *l)
{
	int length;

	length = 0;
	while (line[*i] != '\n')
	{
		length++;
		if (line[*i] == '#')
		{
			touch_sides(line, i, &sh, &l);
			g_t++;
		}
		if ((line[*i] != '#' && line[*i] != '.') || g_t > 4)
			return (0);
		(*i)++;
	}
	if (length != 4)
		return (0);
	return (1);
}

void	touch_sides(char *line, int *i, int **sh, int **l)
{
	if (line[*i + 1] == '#')
		(**sh)++;
	if (line[*i - 1] == '#')
		(**sh)++;
	if (**l != 4 && line[*i + 5] == '#')
		(**sh)++;
	if (**l != 1 && line[*i - 5] == '#')
		(**sh)++;
}

int		valid_tetro(char *line, int *l, int *sh, int *i)
{
	if (*l == 4 && (line[*i + 1] == '\n' || line[*i + 1] == '\0'))
	{
		if ((*sh != 6 && *sh != 8))
			return (0);
		g_t = 0;
		(*i)++;
		*l = 0;
		*sh = 0;
	}
	return (1);
}
