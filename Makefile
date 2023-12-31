# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 17:39:59 by gsaiago           #+#    #+#              #
#    Updated: 2023/11/11 04:06:48 by gsaiago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

SRC_PATH = ./src/

INCLUDE_PATH = ./include/

MLX_PATH =	$(INCLUDE_PATH)minilibx-linux

MLX =	$(MLX_PATH)/libmlx.a

MLX_LINK = -L$(MLX_PATH) -lmlx

LIBFT_PATH = $(INCLUDE_PATH)libft

LIBFT = $(LIBFT_PATH)/libft.a

LIBFT_LINK = -L$(LIBFT_PATH) -lft

CFLAGS = -g 

SRCS = $(SRC_PATH)main.c \
	   $(SRC_PATH)get_params.c \
	   $(SRC_PATH)map_validation.c \
	   $(SRC_PATH)aux1.c \
	   $(SRC_PATH)aux2.c \
	   $(SRC_PATH)aux3.c \
	   $(SRC_PATH)aux4.c \
	   $(SRC_PATH)aux5.c \
	   $(SRC_PATH)aux6.c \
	   $(SRC_PATH)aux7.c \

#$(wildcard *.c)

HEADERS =	$(INCLUDE_PATH)cub3d.h

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT_LINK) $(MLX_LINK) -o -lft -lmlx -lXext -lX11 -lm -o $(NAME)

$(LIBFT): 
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

clean:
	rm -f $(NAME)
	rm -rf $(NAME).dSYM
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

re: clean all

t: all
	./$(NAME) maps/a.cub

val: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) maps/a.cub

fclean: clean
	make fclean -C $(LIBFT_PATH)

.PHONY:
	all re clean fclean
