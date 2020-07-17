.DEFAULT_GOAL: all
.PHONY: all clean fclean re

GCC = gcc $(FLAGS)
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c
INC = includes/ft_printf.h
OBJS = $(SRCS:.c=.o)
LIB = -L libft -lft

all: $(NAME)

%.o: %.c
		$(GCC) -c $< -o $@

lib:
		@echo "building libft"
		make -C libft

$(NAME): $(OBJS) lib
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		rm -f $(OBJS)
		make -C libft clean

fclean: clean
		rm -f $(NAME)
		make -C libft fclean

re: fclean all
