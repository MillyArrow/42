/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:35:53 by marrow            #+#    #+#             */
/*   Updated: 2020/02/18 20:19:01 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <stdio.h>

typedef struct	s_spec
{
	char		flag[5];
	size_t		width;
	int 		accuracy;
	char		length[3];
	char		type;
	char		*format;
	char		plus;
	char		minus;
}				t_spec;

int				ft_printf(const char *restrict format, ...);
void			ft_format_string_analysis(char **str, size_t *i);
void			ft_flags(char **str, size_t *i);
void	    	ft_width(t_spec *specifier, int length);
void			ft_accuracy(t_spec *specifier, int length);
void			ft_length(char **str, size_t *i);
t_spec 			*ft_format_specifier(char *str, size_t *i, t_spec *specifier);
void			ft_set_flag(char *str, size_t *i, t_spec *specifier);
void			ft_set_width(char *str, size_t *i, t_spec *specifier);
void			ft_set_accuracy(char *str, size_t *i, t_spec *specifier);
void			ft__set_length(char *str, size_t *i, t_spec *specifier);
void			ft_set_length(char *str, size_t *i, t_spec *specifier);
void			initialization(t_spec *specifier);
__int64_t		get_number(t_spec *specifier,va_list args);
void			ft_type(t_spec *specifier, va_list args);
void			ft_d(t_spec *specifier, va_list args);
void			ft_c(t_spec *specifaer, va_list args);
void			ft_s(t_spec *specifaer, va_list args);

#endif
