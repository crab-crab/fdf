
##########
# CONFIG #######################################
##########

NAME = fdf
CC = cc

SRCDIR = src
OBJDIR = obj
LIBMLX = lib/MLX42
LIBFT = lib/libft

# -O2 to fold constant math functions
CFLAGS = -O2 -g -Wall -Wextra #-Werror
CPPFLAGS = -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LDFLAGS	= -L$(LIBMLX)/build -L$(LIBFT)
LDLIBS	= -lmlx42 -lft -lglfw -pthread -lm

SRCS =	main.c \
		display.c \
		colour.c \
		draw_line.c \
		draw_grid.c \
		draw_circle.c \
		rotation.c \
		projections.c \
		hook_input.c \
		ingest.c \
		math.c \
		utils.c

# check wildcard usage (%)		
SRCS     := $(addprefix $(SRCDIR)/,$(SRCS))
OBJS     = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)		

#########
# RULES #######################################
#########

all: $(NAME)

# -j4 parallelism
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@$(MAKE) -C $(LIBFT)

#pass headers or -I flag?
$(NAME): libmlx libft $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME) 
	@echo "Linking: $@"

# check wildcard usage (%)
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "Compiling: $(notdir $<)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)



clean:
	@rm -rf $(LIBMLX)/build
	$(MAKE) -C $(LIBFT) clean
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re libmlx libft




