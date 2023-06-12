# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 18:35:35 by gsaiago           #+#    #+#              #
#    Updated: 2023/06/12 19:18:25 by gsaiago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRCS =  ./ft_isalpha.c\
		./ft_isdigit.c\
		./ft_isspace.c\
		./ft_isalnum.c\
		./ft_isascii.c\
		./ft_isprint.c\
		./ft_strlen.c\
		./ft_memset.c\
		./ft_bzero.c\
		./ft_memcpy.c\
		./ft_memmove.c\
		./ft_strlcpy.c\
		./ft_strlcat.c\
		./ft_toupper.c\
		./ft_tolower.c\
		./ft_strchr.c\
		./ft_strchrn.c\
		./ft_strrchr.c\
		./ft_strncmp.c\
		./ft_memchr.c\
		./ft_memcmp.c\
		./ft_strnstr.c\
		./ft_atoi.c\
		./ft_calloc.c\
		./ft_realloc.c\
		./ft_strdup.c\
		./ft_strndup.c\
		./ft_putstr_fd.c\
		./ft_putnbr_fd.c\
		./ft_putchar_fd.c\
		./ft_putendl_fd.c\
		./ft_substr.c\
		./ft_strjoin.c\
		./ft_itoa.c\
		./ft_striteri.c\
		./ft_strmapi.c\
		./ft_strtrim.c\
		./ft_split.c\
		./ft_pow.c\
		./ft_lstnew.c\
		./ft_lstadd_front.c\
		./ft_lstsize.c\
		./ft_lstlast.c\
		./ft_lstadd_back.c\
		./ft_lstdelone.c\
		./ft_lstclear.c\
		./ft_lstiter.c\
		./ft_lstmap.c\
		./ft_lst_remove_if.c\
		./ft_lst_to_mat.c\
		./get_next_line.c\
		./ft_strjoin_gnl.c\
		./ft_printf.c\
		./ft_putstr.c\
		./ft_printhex.c\
		./ft_printptr.c\
		./ft_putnbr.c\
		./ft_putchar.c\
		./ft_free_mat.c\
		./ft_mat_size.c\
		./ft_revstring.c\
		./smartptr.c\

COLOR_GREEN	=	\033[0;32m
COLOR_RED	=	\033[0;31m
COLOR_BLUE	=	\033[0;34m
COLOR_END	=	\033[0m

OBJS = $(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS) 
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(COLOR_GREEN)Libft Compiled :D$(COLOR_END)"

$(OBJS): $(SRCS)
	@$(CC) -c $(CFLAGS) $(SRCS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
