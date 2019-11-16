/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:28:12 by eshor             #+#    #+#             */
/*   Updated: 2019/08/11 22:46:05 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_FUNC_H
# define ALL_FUNC_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_putchar(char c);

void	ft_putnbr(int nb);

int		is_in_arr(int nbr, int *arr);

int		*make_numbers_arr(int **tab, int line, int column);

int		**create_tab(char **argv);

void	print_tab(int **tab);

int		*make_options_arr(int *numbers);

int		ft_strlen(char *str);

int		check_sym(char **argv);

int		check_len(char **argv);

int		is_full(int **tab);

int		check_elem(int **tab);

int		check_tab(int **tab);

int		err17(int **argv);

int		**copy_tab(int **tab);

int		solve(int **tab);

int		solve_reverse(int **tab);

int		compare(int **tab, int **reverse_tab);

#endif
