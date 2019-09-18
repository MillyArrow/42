# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marrow <marrow@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/17 19:09:27 by marrow            #+#    #+#              #
#    Updated: 2019/08/18 23:10:52 by marrow           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
NAME = eval_expr
SRC = *.c
OBJ = *.o
HEADER = ft_list.h
all: $(NAME)
$(NAME):
	$(CC) -c $(CFLAGS) $(SRC) -I $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) -I $(HEADER)
clean:
	rm -rf *.o
fclean:clean
	rm -f $(NAME)
re: fclean all
