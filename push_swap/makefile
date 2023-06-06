# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 14:31:02 by mansanch          #+#    #+#              #
#    Updated: 2023/05/31 17:50:47 by mansanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

SRC =   push_swap.c parce.c parce2.c utils.c

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
	$(CC) $(CCFLAGS) $(SRC) $(LIBFT) $(PRINTF) -o $(NAME) -g

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $< -g

clean:
	@make clean -C libft -s
	@make clean -C ft_printf -s

fclean:
	@make fclean -C libft -s
	@make fclean -C ft_printf -s

re: fclean all

.PHONY: all clean fclean re