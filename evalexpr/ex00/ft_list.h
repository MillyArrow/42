/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:12:30 by marrow            #+#    #+#             */
/*   Updated: 2019/08/18 06:10:47 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

void	ft_putnbr(int nb);

int		ft_putchar(char c);

int		ft_atoi(char *str, unsigned int *index);

int		eval_expr(char *str);

int		ft_ft_strlen(char *str);

int		ft_muldivred(char *str, unsigned int *i);

int		ft_plusminus(char *str, unsigned int *i);

int		ft_factor(char *str, unsigned int *i);

char	*ft_delete_spaces(char *str);

int		ft_strlen_w_s(char *str);

#endif
