# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 14:55:09 by wlin              #+#    #+#              #
#    Updated: 2017/07/22 17:59:45 by wlin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
BUILD_DIR = build/
INC_DIR = include/

SRC_FILE = \
ft_printf \
parse_tag

TEST_FILE = \
fetch_spec.c \
format_flags.c \
format_itoa.c \
format_precision.c \
format_wchar.c \
format_width.c \
parse_fspec.c \
pdispatch.c \
ft_printf.c

SRC = \
$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILE)))\

OBJ = \
$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_FILE)))\

all: $(NAME)

runtest:
	@gcc $(TEST_FILE) ft_printf.h ../libft/libft.a -I ../libft
	@./a.out
	@rm -f ./a.out

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ): $(SRC) $(BUILD_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

$(LIBFT): force
	@cd libft && $(MAKE)

force:
		@true
clean:
	@rm -rf $(BUILD_DIR);
	@cd libft && $(MAKE) fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
