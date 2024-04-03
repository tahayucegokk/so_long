# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muyucego <muyucego@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/30 19:58:25 by muyucego          #+#    #+#              #
#    Updated: 2024/04/03 17:03:30 by muyucego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADERS =	so_long.h mlx/mlx.h ./get_next_line/get_next_line.h

INCLUDES =	mlx/libmlx.a

SOURCES =	so_long.c map_checker.c utils.c get_next_line.c get_next_line_utils.c map_reader.c events.c draw_map.c game_is_possible.c movement.c

DIR_OBJ	= objects
OBJECTS = $(addprefix $(DIR_OBJ)/,$(SOURCES:%.c=%.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

MLX_FLAGS = -g -Lmlx -lmlx -framework OpenGL -framework Appkit



vpath %.c sources get_next_line

all	:	make_lib make_dir $(NAME)

make_lib:
		@make -C mlx

make_dir:
		@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o: %.c $(HEADERS) | make_dir
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJECTS) $(HEADERS)

	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(INCLUDES) -o $(NAME)

clean	:
	@echo "\033[0;91m\nCleaning"
	@echo "\033[0m"
	@make -C mlx clean
	@rm -rf $(DIR_OBJ)

fclean	:	clean
	@rm -rf $(NAME)

re	:	fclean all

.PHONY : all clean fclean re make_dir make_lib
