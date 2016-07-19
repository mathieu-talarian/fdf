# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/06 14:35:06 by mmoullec          #+#    #+#              #
#    Updated: 2016/07/19 13:07:18 by mmoullec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc -Wall -Werror -Wextra
MLX = -lmlx -framework openGL -framework AppKit
LIB = -lft -L./libft
LIBI = -I./libft
INC = -I./includes
SRC_DIR = ./srcs/
SRCS = datas.c\
	   main.c\
	   fdf_errors.c\
	   fdf_listing.c\
	   fil_de_fer.c\
	   fonctions_transfo.c\
	   mlx_draw.c\
	   mlx_util.c\
	   mlx_print.c\
	   redraw.c\
	   hook.c\
	   utilities.c\
	   mlx_init.c\
	   find_color.c\
	   free_lists.c\
	   mlx_screen.c\
	   mlx_calcs.c

OBJ_FILES = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@make fclean -C libft
	@make -C libft
	@echo "lib"
	@$(CC) -o $(NAME) $^ $(OBJ) $(INC) $(LIB) $(MLX)
	@echo "file Created"

%.o: $(SRC_DIR)%.c
	@$(CC) $(INC) -o $@ -c $< $(LIBI)

clean:
	@make clean -C libft
	@rm $(OBJ_FILES)
	@echo "clean ok"

fclean: clean
	@rm $(NAME)
	@echo "fclean ok"

re: fclean all

.PHONY: all clean fclean re
