

NAME = tutorial
CC = cc
CFLAGS = -g -Wall -Wextra #-Werror

LIBMLX = lib/MLX42
LIBFT = lib/libft

HEADERS = -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS = -L$(LIBMLX)/build -lmlx42 -L$(LIBFT) -lft -lglfw -pthread -lm

SRCS =	src/main.c \
		src/line_draw.c \
		src/hook_test.c \
		src/colour.c \
		src/ingest.c \
		src/grid_draw.c

OBJS = $(SRCS:.c=.o)

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@$(MAKE) -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(LIBMLX)/build
	$(MAKE) -C $(LIBFT) clean
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re libmlx libft




