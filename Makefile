# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 16:31:26 by zamohame          #+#    #+#              #
#    Updated: 2025/02/27 14:45:48 by zamohame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ../greg_lib

LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./minilibx-linux

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
MLX_FLAGS = -L $(MLX_DIR) -lmlx -L /usr/lib -lXext -lX11

SRC = src/main.c \
      src/utils.c \
	  src/parsing.c \
	  src/game_logic.c \
	  src/player.c \
	  src/rendering.c \
	  src/hooks.c \
	  src/cleanup.c \

OBJ = $(SRC:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I $(MLX_DIR) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
