# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 15:55:25 by mansanch          #+#    #+#              #
#    Updated: 2022/11/29 13:52:22 by mansanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs

NAME = libftprintf.a

INCLUDE = ft_printf.h

SRC = ft_printf.c printf_types.c printf_types2.c

OBJECTS = $(SRC:.c=.o)

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
	$(LIB) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f *.o

fclean:
	rm -f *.o $(NAME)


re:	fclean all