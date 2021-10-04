NAME = so_long

CC = clang
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(INC_DIR) -I$(MLX_DIR)

SRCS_DIR = srcs
INC_DIR = includes
OBJS_DIR = objs
MLX_DIR = minilibx-linux

INC = so_long.h mlx.h mlx_int.h
SRCS = so_long.c errors.c initialize.c get_next_line.c get_next_line_utils.c parsing_map.c parsing_map2.c parsing_map3.c draw.c mlx_draw.c events.c actualization.c shift.c free.c
MLX = libmlx.a

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
vpath	%.c $(shell find $(SRCS_DIR) -type d)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
		$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

all: init $(NAME)

init:
	$(shell mkdir -p $(OBJS_DIR))

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re make init
