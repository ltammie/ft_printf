.DEFAULT_GOAL: all
.PHONY: all clean fclean re debug

GCC = gcc $(FLAGS)
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
NAME_E = printf
LIB_DIR = lib/
SRC_DIR = src/
SRCS = 	$(LIB_DIR)ft_abs.c\
		$(LIB_DIR)ft_atoi.c\
		$(LIB_DIR)ft_char_in_str.c\
		$(LIB_DIR)ft_isdigit.c\
		$(LIB_DIR)ft_isspace.c\
		$(LIB_DIR)ft_itoa.c\
		$(LIB_DIR)ft_itoa_base.c\
		$(LIB_DIR)ft_lltoa.c\
		$(LIB_DIR)ft_putchar.c\
		$(LIB_DIR)ft_putstr.c\
		$(LIB_DIR)ft_str_to_lower.c\
		$(LIB_DIR)ft_strcat.c\
		$(LIB_DIR)ft_strcmp.c\
		$(LIB_DIR)ft_strcpy.c\
		$(LIB_DIR)ft_strdup.c\
		$(LIB_DIR)ft_strjoin.c\
		$(LIB_DIR)ft_strjoin_free.c\
		$(LIB_DIR)ft_strlen.c\
		$(LIB_DIR)ft_strnew.c\
		$(LIB_DIR)ft_strsub.c\
		$(LIB_DIR)ft_tolower.c\
		$(LIB_DIR)ft_ulltoa_base.c\
		$(LIB_DIR)ft_utoa.c\
		$(LIB_DIR)ft_utoa_base.c\
		$(SRC_DIR)ft_printf.c\
		$(SRC_DIR)parse.c\
		$(SRC_DIR)parse_flags.c\
		$(SRC_DIR)parse_precision.c\
		$(SRC_DIR)parse_type.c\
		$(SRC_DIR)parse_width.c\
		$(SRC_DIR)parse_length.c\
		$(SRC_DIR)pr.c\
		$(SRC_DIR)c_pr.c\
		$(SRC_DIR)s_pr.c\
		$(SRC_DIR)percent_pr.c\
		$(SRC_DIR)uox_pr.c\
		$(SRC_DIR)di_pr.c\
		$(SRC_DIR)pointer_pr.c\
		$(SRC_DIR)f_pr.c\
		$(SRC_DIR)utils.c\
		$(SRC_DIR)float_utils.c\
		$(SRC_DIR)float_utils2.c\
		$(SRC_DIR)float_utils3.c\
		$(SRC_DIR)long_arithmetics.c\
		$(SRC_DIR)long_arithmetics2.c\
		$(SRC_DIR)cast.c

INC = includes/
OBJS = $(SRCS:.c=.o)

all: $(NAME)

src%.o: %.c
		$(GCC) -c $< -o $@ -I $(INC)

$(NAME):$(OBJS) $(INC)ft_printf.h
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
