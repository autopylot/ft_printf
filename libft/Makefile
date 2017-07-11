NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJ = $(patsubst %.c,%.o,$(wildcard ./*.c))

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
	
.PHONY: clean fclean re
