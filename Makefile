# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 16:31:26 by zamohame          #+#    #+#              #
#    Updated: 2025/04/08 16:44:37 by zamohame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = greg_lib
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -fPIE
MLX_FLAGS = -L $(MLX_DIR) -lmlx -L /usr/lib -lXext -lX11

SRC = src/so_long.c \
      src/utils.c \
	  src/map.c \
	  src/game.c \
	  src/player.c \
	  src/render.c \
	  src/hooks.c \
	  src/path.c \
	  src/clean.c \

BONUS_SRC = bonus/so_long.c \
      		bonus/utils.c \
	  		bonus/map.c \
	  		bonus/game.c \
	  		bonus/player.c \
	  		bonus/render.c \
	  		bonus/hooks.c \
	  		bonus/path.c \
	  		bonus/clean.c \
			bonus/villain.c \
            bonus/move_count.c \
            bonus/animation.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

NAME = so_long
BONUS_NAME = so_long_bonus

all: $(NAME)
bonus: $(BONUS_NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(MLX_FLAGS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I ../include -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
