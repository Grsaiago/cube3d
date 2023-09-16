# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 17:39:59 by gsaiago           #+#    #+#              #
#    Updated: 2023/06/28 11:59:47 by gsaiago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc

SRC_PATH = ./src/

LIBFT_PATH = ./include/libft

INCLUDE_PATH = ./include/

LIBFT = $(LIBFT_PATH)/libft.a

LIBFT_LINK = -L$(LIBFT_PATH) -lft

CFLAGS = -g -Wall -Wextra -Werror

SRCS = $(SRC_PATH)main.c \
	   $(SRC_PATH)get_params.c \
	   $(SRC_PATH)map_validation.c \

#$(wildcard *.c)

HEADERS =	$(INCLUDE_PATH)cub3d.h

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBFT_LINK)

$(LIBFT): 
	make -C $(LIBFT_PATH)

clean:
	rm -f $(NAME)
	rm -rf $(NAME).dSYM
	make clean -C $(LIBFT_PATH)

re: clean all

fclean: clean
	make fclean -C $(LIBFT_PATH)

.PHONY:
	all re clean fclean
