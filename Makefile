.DEFAULT_GOAL: all
.PHONY: all clean fclean re

GCC = gcc $(FLAGS)
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c
INC = includes/ft_printf.h
OBJS = $(SRCS:.c=.o)
LIB = -L libft -lft

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
PURPLE = \033[0;36m
STANDART = \033[0m

all: $(NAME)

%.o: %.c
		$(GCC) -c $< -o $@

lib:
		@echo "$(PURPLE)$(NAME): $(GREEN)Building libft $(YELLOW)"
		make -C libft
		@echo "$(GREEN)libft building successful!$(STANDART)"

$(NAME):$(OBJS) lib
		@echo "$(PURPLE)$(NAME): $(GREEN)Building libftprintf $(YELLOW)"
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
		@echo "$(GREEN)libftprintf building successful!$(STANDART)"

clean:
		make -C libft clean
		rm -f $(OBJS)

fclean: clean
		make -C libft fclean
		rm -f $(NAME)

re: fclean all
