NAME := so_long

CFLAGS := -Wall -Wextra -Werror -Iincludes

MLX := -Lminilibx-linux -lmlx_Linux -lXext -lX11

CC = cc

SRCS := so_long.c event_handler.c graphics.c  functions_needed.c parsing_utils.c parsing.c parsing_utils2.c moves_utils.c check_map.c graphics_utils.c parsing_utils3.c \
		../gnl/get_next_line.c \
		../gnl/get_next_line_utils.c \

OBJS := $(SRCS:.c=.o)

HEADER := so_long.h

all: $(NAME)

$(NAME): $(OBJS)
		make -C ../ft_printf
		cp -rf ../ft_printf/libftprintf.a ../src
		$(CC) $(CFLAGS) $(OBJS) $(MLX) libftprintf.a -o $(NAME)


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		make clean -C ../ft_printf
		rm -rf $(OBJS)
fclean: clean
		rm -rf $(NAME) libftprintf.a ../ft_printf/libftprintf.a
re: fclean all

.PHONY: clean
.SECONDARY: $(OBJS)