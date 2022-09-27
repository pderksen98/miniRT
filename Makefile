# -*- Makefile -*-
NAME := miniRT

# ifndef DEBUG
# CFLAGS := -Wall -Wextra -Werror
# else
# CFLAGS := -Wall -Wextra -Werror -fsanitize=address -g
# endif

CFLAGS := -Wall -Wextra -Werror

CC := gcc

SRCS :=	src/main.c \
		src/mlx.c

HEADERFILES := minirt.h

LIBFT := libft/libft.a

MLX := mlx/libmlx.dylib

all: $(NAME)
	
$(NAME) : $(SRCS) $(LIBFT) $(MLX)
		$(CC) $(CFLAGS) -o $@ $^

$(LIBFT) :
		$(MAKE) -C libft

$(MLX) :
		$(MAKE) -C mlx && (test -e libmlx.dylib || ln -sf mlx/libmlx.dylib libmlx.dylib)

clean :
		$(MAKE) clean -C libft 

fclean:
		$(MAKE) fclean -C libft
		$(MAKE) clean -C mlx
		rm -f $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re