NAME = push_swap

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I$(LIBFT_DIR)

SRCS = main.c parse_flags.c parse_numbers.c algo_simple.c check_numbers.c stack_utils.c algo_medium.c\
	   algo_medium_utils.c \
	   operations/rotate_a.c \
	   operations/rotate_b.c \
	   operations/rrotate_a.c \
	   operations/rrotate_b.c \
	   operations/push_a.c \
	   operations/push_b.c \
	   operations/swap_a.c \
	   operations/swap_b.c 
	   
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re