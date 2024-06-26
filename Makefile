# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 11:32:58 by cgaratej          #+#    #+#              #
#    Updated: 2024/05/13 10:20:02 by cgaratej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = utils/libft/libft.a
GET_NEX_LINE= utils/libft/get_next_line/libftget_next_line.a
PRINTF= utils/libft/ft_printf/libftprintf.a
LIBFT_MAKE = make --no-print-directory -C utils/libft
MINILIBX =	utils/minilibx/libmlx.a
MINILIBX_MAKE =  make --no-print-directory -C utils/minilibx

NAME = so_long
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -L./utils/minilibx
INCLUDE = Makefile includes/*
CC = gcc
RM = rm -f

GREEN=\033[0;32m
LGREEN=\033[1;92m
ORANGE=\033[33m
RED = \033[1;91m
NONE=\033[0m

SRC= src/main.c src/imagen.c \
	src/game_over.c src/map/map.c src/map/map_utlis.c \
	src/map/map_check.c src/map/map_render.c src/player/movements.c \
	src/player/mov_utils.c

SRC_BONUS= src_bonus/main_bonus.c src_bonus/imagen_bonus.c \
	src_bonus/game_over_bonus.c src_bonus/map/map_bonus.c src_bonus/map/map_utlis_bonus.c \
	src_bonus/map/map_check_bonus.c src_bonus/map/map_render_bonus.c \
	src_bonus/player/movements_bonus.c src_bonus/player/mov_utils_bonus.c src_bonus/player/player_animatios_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): libft minilib $(OBJ) $(INCLUDE)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT) $(GET_NEX_LINE) $(PRINTF) $(MINILIBX) $(OBJ) -o $(NAME)
	@echo "\n$(LGREEN)Create $(NAME) ✔\n$(NONE)"

bonus: libft minilib $(INCLUDE) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT) $(GET_NEX_LINE) $(PRINTF) $(MINILIBX) $(OBJ_BONUS) -o $(NAME)
	@echo "\n$(LGREEN)Create $(NAME) bonus ✔\n$(NONE)"

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@
	@echo "$(LGREEN)File $< compiled ✔$(NONE)"

libft:
	@echo "$(ORANGE)\nCompilando libft$(NONE)"
	@$(LIBFT_MAKE)

minilib:
	@echo "$(ORANGE)\nCompilando minilib$(NONE)"
	@$(MINILIBX_MAKE)

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@$(LIBFT_MAKE) clean
	@$(MINILIBX_MAKE) clean
	@echo "$(RED)Deleted .o files$(NONE)"
	
fclean: clean
	@$(RM) $(NAME)
	@$(LIBFT_MAKE) fclean
	@echo "$(RED)$(NAME) Deleted$(NONE)"

re: fclean all

.PHONY: all clean fclean re libft minilib bonus