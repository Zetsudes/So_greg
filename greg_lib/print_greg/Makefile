# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zamohame <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 20:50:09 by zamohame          #+#    #+#              #
#    Updated: 2024/11/15 20:59:52 by zamohame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
AR = ar

SRC = ft_printf.c \
	handle_char.c \
	handle_hex.c \
	handle_number.c \
	handle_percent.c \
	handle_pointer.c \
	handle_string.c \
	handle_unsigned.c \

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) -r $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
