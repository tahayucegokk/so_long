# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muyucego <muyucego@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 18:17:29 by muyucego          #+#    #+#              #
#    Updated: 2024/04/03 18:22:52 by muyucego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror 


SRCS = draw_map.c events.c game_is_possible.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c map_checker.c map_reader.c movement.c so_long.c utils.c
                          
OBJS = $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
			@ make -C mlx all 
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit

all:		${NAME}

clean:
			@ rm -rf $(NAME)
			@ rm -rf $(OBJS)
			@ make -C mlx clean

fclean:		clean
			@ rm libmlx.a

re:			fclean all

.PHONY:		all clean fclean re