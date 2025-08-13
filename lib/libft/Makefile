
# Flags
CC = cc
AR = ar
ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror -g

# Source and Object Files
SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_printf.c \
		pt_char.c \
		pt_decimal.c \
		pt_hexi.c \
		pt_percent.c \
		pt_pointer.c \
		pt_string.c \
		pt_udecimal.c \
		ft_uitoa.c \
		hexa.c \
		ft_lst_fill.c \
		ft_lst_print.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstinnit.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstremove.c \
		ft_lstsize.c \
		st_push.c \
		st_rerotate.c \
		st_rotate.c \
		st_swap.c
	
OBJS = $(SRCS:.c=.o)
NAME = libft.a

# set default target
all: $(NAME)

# build archive/library
$(NAME) : $(OBJS)
	@echo "making Libft..."
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean up
clean:
	@echo "Cleaning Libft..."
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make

.PHONY: all clean fclean re bonus