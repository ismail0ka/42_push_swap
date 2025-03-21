CC= cc
CFLAGS= -Wall -Wextra -Werror -Iheaders -g3
NAME= push_swap

ARCHIVES = libft/libft.a \
	ft_printf/libftprintf.a

SRCS= parse_utils/has_empty_str.c \
	parse_utils/validate_args.c \
	parse_utils/free_args.c \
	parse_utils/ft_atol.c \
	ops/op_px.c \
	ops/op_sx.c \
	ops/op_ss.c \
	ops/op_rx.c \
	ops/op_rr.c \
	ops/op_rrx.c \
	ops/op_rrr.c \
	sort_utils/move_to_top.c \
	sort_utils/get_max.c \
	sort_utils/get_min.c \
	sort_utils/quick_sort.c \
	sort_utils/short_sort.c \
	sort_utils/sort.c \
	sort_utils/is_sorted.c \
	sort_utils/max_is_on_b.c \
	ft_stack_new.c \
	main.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(ARCHIVES) $(OBJS)
	$(CC) $(OBJS) $(ARCHIVES) -o $(NAME)

$(ARCHIVES):
	$(MAKE) -C libft/ && $(MAKE) -C libft/ clean
	$(MAKE) -C ft_printf/ && $(MAKE) -C ft_printf/ clean

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C libft/ clean
	$(MAKE) -C ft_printf/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft/ fclean
	$(MAKE) -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re