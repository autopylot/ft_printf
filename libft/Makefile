# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/28 21:23:39 by wlin              #+#    #+#              #
#    Updated: 2017/07/29 12:24:27 by wlin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -O2

HEADER = libft.h

LIBFILES = $(addsuffix .o, $(SRC))
SRCFILES = $(addsuffix .c, $(SRC))

SRC = \
ft_bzero \
ft_memalloc \
ft_memchr \
ft_memcpy \
ft_memmove \
ft_putchar \
ft_putstr \
ft_strcat \
ft_strchr \
ft_strcpy \
ft_strdel \
ft_strdup \
ft_strlen \
ft_strnew \
strjoin_f \
ft_memset

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRCFILES) -I $(HEADER)
	@ar rc $(NAME) $(LIBFILES)
	@ranlib $(NAME)

clean:
	@rm -f $(LIBFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
