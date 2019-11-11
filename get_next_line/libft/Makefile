# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marrow <marrow@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 21:44:43 by marrow            #+#    #+#              #
#    Updated: 2019/11/10 02:40:08 by marrow           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = libft.h
SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_create_elem.c \
		ft_copybyte.c \
		ft_isblanki.c \
		ft_islower.c \
		ft_isupper.c \
		ft_strnlen.c \
		ft_mem{alloc,ccpy,chr,cmp,cpy,del,move,set}.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_is{alpha,print,alnum,ascii,digit}.c \
		ft_str{iter,iteri}.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_str{map,mapi}.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_to{lower,upper}.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_put{char,str,endl,nbr}.c \
		ft_put{char,str,endl,nbr}_fd.c \
		ft_lst{new,add,del,delone,iter,map}.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
