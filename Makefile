# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esellier <esellier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 18:15:13 by esellier          #+#    #+#              #
#    Updated: 2024/06/23 21:06:52 by esellier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =   fractol_checks.c \
		fractol_atoi.c \
		fractol_implementation.c \
		fractol_events.c \
		fractol_fractals.c \
		fractol_create_colors.c \
		fractol_manage_colors.c \
		main.c
		
LIB_FLAGS = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -Llibft -lft

CC = gcc
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

OBJ = $(SRC:.c=.o) 

all :
	@make -C libft --no-print-directory
	@make -C mlx --no-print-directory
	@make $(NAME) --no-print-directory

%.o : %.c Makefile fractol.h libft/libft.a mlx/libmlx_Linux.a
	$(CC) $(FLAGS) -I./libft -I./mlx -o $@ -c $<

$(NAME) : $(OBJ) Makefile fractol.h
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIB_FLAGS)

clean :
	make clean -C libft
	make clean -C mlx
	rm -f *.o

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all
	make re -C libft
	make re -C mlx

.PHONY: all clean fclean re
