# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 14:31:02 by mansanch          #+#    #+#              #
#    Updated: 2023/05/26 16:04:48 by mansanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

SRC =	client.c server.c

PRINTF = ft_printf/libftprintf.a

BONUSSRC = client_bonus.c server_bonus.c

BONUSOBJ = $(BONUSSRC:.c=.o)

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

ifdef LEAKS
	CC += -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft -s 
	@make -C ft_printf -s
	$(CC) $(CCFLAGS) client.c $(LIBFT) $(PRINTF) -o client
	$(CC) $(CCFLAGS) server.c $(LIBFT) $(PRINTF) -o server

bonus:
	@make -C libft -s 
	@make -C ft_printf -s
	$(CC) $(CCFLAGS) client_bonus.c $(LIBFT) $(PRINTF) -o client_bonus
	$(CC) $(CCFLAGS) server_bonus.c $(LIBFT) $(PRINTF) -o server_bonus

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	@make clean -C libft -s
	@make clean -C ft_printf -s
	rm -rf *.o

fclean:
	@make fclean -C libft -s
	@make fclean -C ft_printf -s
	rm -rf *.o client server client_bonus server_bonus

re: fclean all

.PHONY: all clean fclean re