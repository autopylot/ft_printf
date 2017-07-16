# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 14:55:09 by wlin              #+#    #+#              #
#    Updated: 2017/07/15 20:17:11 by wlin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
BUILD_DIR = build/
INC = -I include/

SRC_CHAR = \
ft_remchr \
ft_replchr \
ft_isalnum \
ft_isalpha \
ft_isascii \
ft_isdigit \
ft_isprint \
ft_tolower \
ft_toupper \

SRC_IO = \
ft_putchar_fd \
ft_putchar \
ft_putendl_fd \
ft_putendl \
ft_putnbr_fd \
ft_putnbr \
ft_putstr_fd \
ft_putstr \

SRC_LST = \
ft_lstadd \
ft_lstdel \
ft_lstdelone \
ft_lstiter \
ft_lstmap \
ft_lstnew \
ft_lstprint \

SRC_MEM = \
ft_bzero \
ft_memalloc \
ft_memccpy \
ft_memchr \
ft_memcmp \
ft_memcpy \
ft_memdel \
ft_memmove \
ft_memset \

SRC_STR = \
ft_atoi \
ft_itoa_base \
ft_itoa \
ft_strcat \
ft_strchr \
ft_strcmp \
ft_strcpy \
ft_strdel \
ft_strdup \
ft_strequ \
ft_striter \
ft_striteri \
ft_strjoin \
ft_strlcat \
ft_strlen \
ft_strmap \
ft_strmapi \
ft_strncat \
ft_strncmp \
ft_strncpy \
ft_strnequ \
ft_strnew \
ft_strnstr \
ft_strrchr \
ft_strrev \
ft_strsplit \
ft_strstr \
ft_strsub \
ft_strtrim

SRC = \
$(addprefix $(SRC_DIR)char/, $(addsuffix .c, $(SRC_CHAR)))\
$(addprefix $(SRC_DIR)io/, $(addsuffix .c, $(SRC_IO)))\
$(addprefix $(SRC_DIR)lst/, $(addsuffix .c, $(SRC_LST)))\
$(addprefix $(SRC_DIR)mem/, $(addsuffix .c, $(SRC_MEM)))\
$(addprefix $(SRC_DIR)str/, $(addsuffix .c, $(SRC_STR)))

OBJ = \
$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_CHAR)))\
$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_IO)))\
$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_LST)))\
$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_MEM)))\
$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_STR)))


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"
	@echo ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
	@echo ░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░
	@echo ░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░
	@echo ░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░
	@echo ░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░
	@echo ░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░
	@echo ░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░
	@echo ░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░
	@echo ░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░
	@echo ░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░
	@echo ░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░
	@echo ░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░
	@echo ░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░
	@echo ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░


$(OBJ): $(SRC) $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

clean:
	@rm -rf $(BUILD_DIR);

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
