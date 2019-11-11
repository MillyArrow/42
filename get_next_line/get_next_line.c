/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:54:42 by marrow            #+#    #+#             */
/*   Updated: 2019/11/08 13:54:43 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	newline(char **str, char **line)
{
	int		length;
	char	*temp;

	length = 0;
	while (*str != '\0' || *str != '\n')
	{
		*str++;
		length++;
	}
	if (*str == '\n')
	{
		*line = ft_strsub(*str, 0, length);
		//temp = ft_strdup(*str);
		free(*str);
		*str = temp;
	}
	return ;
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		buffer[BUFF_SIZE + 1];
	static char	*str[255];
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while (ret = read(fd, buffer, BUFF_SIZE) > 0)
	{
		buffer[ret] = '\0';
		if (str[fd] = NULL)
			str[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(str[fd], buffer);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return ;
}
