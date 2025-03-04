CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS = ft_printf.c \
       ft_printf_utils/handle_format.c \
       ft_printf_utils/ft_put_unsigned_nbr.c \
       ft_printf_utils/ft_putptr.c \
       ft_printf_utils/ft_putstr.c \
       ft_printf_utils/ft_putchar.c \
       ft_printf_utils/ft_putnbr.c \
       ft_printf_utils/ft_strlen.c \
       ft_printf_utils/ft_puthex.c \
       ft_printf_utils/ft_strcpy.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
