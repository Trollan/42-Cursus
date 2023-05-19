# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 14:31:02 by mansanch          #+#    #+#              #
#    Updated: 2023/05/17 18:59:44 by mansanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX42 = MLX42/libmlx42.a -I include -lglfw -L "/Users/mansanch/.brew/opt/glfw/lib/"

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRC = $(GNL) main.c read_map.c check_map.c \
		game_manager.c draw_map.c draw_map2.c check_move.c game_manager2.c valid_path.c

PRINTF = ft_printf/libftprintf.a

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

ifdef LEAKS
	CC += -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft -s 
	@make -C ft_printf -s
	@make -s -C MLX42
	$(CC) $(CCFLAGS) $(SRC) $(LIBFT) $(PRINTF) $(MLX42) -o $(NAME) -g

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $< -g

clean:
	@make clean -C libft -s
	@make clean -C ft_printf -s
	@make clean -C MLX42 -s
	rm -rf *.o get_next_line/*.o

fclean:
	@make fclean -C libft -s
	@make fclean -C ft_printf -s
	@make fclean -s -C MLX42
	rm -rf *.o get_next_line/*.o $(NAME)

re: fclean all

.PHONY: all clean fclean re