# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 14:55:09 by wlin              #+#    #+#              #
#    Updated: 2017/08/01 10:48:37 by wlin             ###   ########.fr        #
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

SRC = \
$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = \
$(addprefix $(BUILD_DIR), $(SRC_FILES:.c=.o))
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR)
	@cp libft/libft.a ./$(NAME)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

test: re
	@$(CC) $(CFLAGS) -I $(INC_DIR) test.c -L. -lftprintf
	@./a.out

norme:
	norminette ./libft/
	@echo
	norminette ./$(INC_DIR)/
	@echo
	norminette ./$(SRC_DIR)/

clean:
	@rm -f $(OBJ)
	@rm -rf $(BUILD_DIR)
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re
