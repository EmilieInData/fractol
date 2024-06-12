NAME = fractol

SRC =   fractol_utils.c \
		fractol_atoi.c \
		fractol_implementation.c \
		main.c
		
LIB_A = libft/libft.a
MLX_A = mlx/libmlx_Linux.a
LIB_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

CC = gcc
FLAGS = -Wall -Wextra -Werror #-O3

OBJ = $(SRC:.c=.o) 

all :
	@make -C libft --no-print-directory
	@make -C mlx --no-print-directory
	@make $(NAME) --no-print-directory

%.o : %.c Makefile fractol.h
	$(CC) $(FLAGS) -I./libft -I./mlx -o $@ -c $<

$(NAME) : $(OBJ) $(LIB_A) $(MLX_A) Makefile fractol.h
	$(CC) $(FLAGS) $(LIB_A) $(MLX_A) $(OBJ) -o $(NAME) $(LIB_FLAGS)

clean :
	make clean -C libft -C mlx
	rm -f *.o

fclean : clean
	make fclean -C libft -C mlx
	rm -f $(NAME)

re : fclean all
	make -C re libft mlx

.PHONY: all clean fclean re
