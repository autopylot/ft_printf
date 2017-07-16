# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 14:55:09 by wlin              #+#    #+#              #
#    Updated: 2017/07/15 20:50:58 by wlin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_print

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
BUILD_DIR = build/
INC = -I include/
LIBFT = ./libft/libft.a

SRC_FILE = \
ft_printf \
parse_tag \

SRC = \
$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILE)))\


OBJ = \
$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_FILE)))\

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $<

$(OBJ): $(SRC) $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

$(LIBFT): force
	cd libft && $(MAKE)
force:
		@true
clean:
	@rm -rf $(BUILD_DIR);
	cd libft && $(MAKE) fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
