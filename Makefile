# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaiago <gsaiago@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 17:39:59 by gsaiago           #+#    #+#              #
#    Updated: 2023/06/12 17:55:10 by gsaiago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

LIBFT_LINK = -L$(LIBFT_PATH) -lft

CFLAGS = -g -Wall -Wextra -Werror

SRCS = $(wildcard *.c)

HEADERS =

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
