# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 14:55:09 by wlin              #+#    #+#              #
#    Updated: 2017/07/29 12:15:37 by wlin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIB_DIR = libft/
SRC_DIR = src/
BUILD_DIR = build/
INC_DIR = include/

SRC_FILES = \
parse_fspec.c \
fetch_spec.c \
format_flags.c \
format_itoa.c \
format_precision.c \
format_wchar.c \
format_width.c \
pdispatch.c \
ft_printf.c

# LIBFT_FILE = \
# ft_bzero \
# ft_memalloc \
# ft_memchr \
# ft_memcpy \
# ft_memmove \
# ft_putchar \
# ft_putstr \
# ft_strcat \
# ft_strchr \
# ft_strcpy \
# ft_strdel \
# ft_strdup \
# ft_strlen \
# ft_strnew \
# strjoin_f



SRC = \
$(addprefix $(SRC_DIR), $(SRC_FILES)) \
#$(addprefix $(LIB_DIR), $(addsuffix .c, $(LIBFT_FILE)))

OBJ = \
$(addprefix $(BUILD_DIR), $(SRC_FILES:.c=.o)) \
#$(addprefix $(BUILD_DIR), $(addsuffix .o, $(LIBFT_FILE)))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR)
	@cp libft/libft.a ./$(NAME)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(BUILD_DIR)%.o: $(SRC_DIR)%.c $(BUILD_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

# $(OBJ): $(SRC) $(BUILD_DIR)
# 	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

norme:
	norminette ./libft/
	@echo
	norminette ./$(INC_DIR)/
	@echo
	norminette ./$(SRC_DIR)/

clean:
	@rm -rf $(BUILD_DIR);
	@cd libft && $(MAKE) fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
