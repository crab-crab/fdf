

NAME = tutorial
CC = cc
CFLAGS = -g -Wall -Wextra #-Werror

LIBMLX = lib/MLX42
LIBFT = lib/libft

HEADERS = -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS = -L$(LIBMLX)/build -lmlx42 -L$(LIBFT) -lft -lglfw -pthread -lm

SRCDIR = src
OBJDIR = obj

SRCS =	$(SRCDIR)/main.c \
		$(SRCDIR)/display.c \
		$(SRCDIR)/colour.c \
		$(SRCDIR)/draw_line.c \
		$(SRCDIR)/draw_grid.c \
		$(SRCDIR)/draw_circle.c \
		$(SRCDIR)/rotation.c \
		$(SRCDIR)/projections.c \
		$(SRCDIR)/hook_test.c \
		$(SRCDIR)/hook_input.c \
		$(SRCDIR)/ingest.c \
		$(SRCDIR)/constants.c \
		$(SRCDIR)/math.c \
		$(SRCDIR)/debug.c
		
		

# check wildcard usage (%)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@$(MAKE) -C $(LIBFT)

# check wildcard usage (%)
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

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




