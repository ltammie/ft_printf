.DEFAULT_GOAL: all
.PHONY: all clean fclean re debug

GCC = gcc $(FLAGS)
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c\
		parse.c\
		parse_flags.c\
		parse_precision.c\
		parse_type.c\
		parse_width.c\
		parse_length.c\
		pr.c\
		c_pr.c\
		s_pr.c\
		percent_pr.c\
		uoxX_pr.c\
		di_pr.c\
		pointer_pr.c\
		utils.c\
		u_cast.c


INC = includes/ft_printf.h
OBJS = $(SRCS:.c=.o)
LIB = -L libft -lft

#DEBUG
DEBUG_NAME = test

#colors
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;36m
DEBUG = \033[0;46m
STANDART = \033[0m

all: $(NAME)

%.o: %.c
		$(GCC) -c $< -o $@

lib:
		@echo "$(BLUE)$(NAME): $(GREEN)Building libft.$(YELLOW)"
		make -C libft
		@echo "$(GREEN)libft building successful!$(STANDART)"

$(NAME):$(OBJS) lib
		@echo "$(BLUE)$(NAME): $(GREEN)Building libftprintf.$(YELLOW)"
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
		@echo "$(GREEN)libftprintf building successful!$(STANDART)"

clean:
		make -C libft clean
		rm -f $(OBJS)

fclean: clean dclean
		make -C libft fclean
		rm -f $(NAME)

re: fclean all

debug: all
		@echo "$(DEBUG)Building test version.$(YELLOW)"
		$(GCC) -c main.c -I $(INC)
		$(GCC) -o $(DEBUG_NAME) main.o $(NAME) libft/libft.a
		@echo "$(DEBUG)Test building successful!$(STANDART)"
dclean:
		@echo "$(RED)Test version delete.$(YELLOW)"
		rm -rf $(DEBUG_NAME) main.o
		@echo "$(GREEN)Test version deleted!$(STANDART)"

