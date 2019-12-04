/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:32:19 by bashe             #+#    #+#             */
/*   Updated: 2019/12/04 20:07:14 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H
# include "libft.h"

typedef struct		s_map
{
	int				size;
	char			**array;
}					t_map;

typedef struct		s_point
{
	int				x[4];
	int				y[4];
}					t_point;

typedef struct		s_fillit
{
	t_point			*coordinate;
	char			character;
	int				width;
	int				height;
	struct s_fillit	*next;
}					t_fillit;

int					validation(char *line);
int					valid_file(char *line, int *i, int *l, int *sh);
int					valid_string(char *line, int *i, int *sh, int *t);
void				touch_sides(char *line, int *i, int **sh, int **l);
int					valid_tetro(char *line, int *l, int *sh, int *i);
t_fillit			*get_figure(char *line, t_fillit *head, char set);
t_fillit			*create(void);
t_fillit			*new_node(t_fillit *head);
t_fillit			*read_figure(char *line, t_fillit *head, int *i);
void				get_xmin(char *line, int *xmin);
void				get_coordinate(char *line, t_fillit *head, int *xmin);
t_map				*map_create(int size);
void				map_print(t_map *map);
void				free_map(t_map *map);
int					ft_sqrt(int a);
void				ft_list_reverse(t_fillit **head);
void				map_clean(t_map *map, t_fillit *head, int x, int y);
int					solve_map(t_map *map, t_fillit *head);
void				place_tetro(t_map *map, t_fillit *head, int x, int y);
t_map				*solve(t_fillit *head, int *i);
int					check_dot(t_map *map, t_fillit *head, int x, int y);
void				free_fillit(t_fillit *head, t_map *map);
void				error(t_fillit *head);
t_fillit			*free_list(t_fillit *head);

#endif
