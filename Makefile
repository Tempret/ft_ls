#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 15:20:54 by dkhlopov          #+#    #+#              #
#    Updated: 2017/06/21 15:13:50 by dkhlopov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

LIB = libft.a

FLAGS = -Wall -Wextra -Werror 

SRC = ls_main.c

OBJ = $(SRC:.c=.o)

all : $(LIB) $(NAME)

$(LIB) : 
	make -C ./libft

%.o : ./src/%.c
	gcc $(FLAGS) -c -o $@ $< -I./includes

$(NAME) : $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

libclean : 
	make clean -C ./libft

libfclean : libclean
	make fclean -C ./libft
