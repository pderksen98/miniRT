# -*- Makefile -*-
NAME := miniRT

# Colors
GREEN=\033[0;32m
RED=\033[0;31m
COLOUR_END=\033[0m
CYAN=\033[0;36m

ifndef DEBUG
CFLAGS := -Wall -Wextra -Werror
else
CFLAGS := -Wall -Wextra -Werror -fsanitize=address -g
endif

CC := gcc

SRCS :=	src/main.c \
		src/camera.c \
		src/vector_get.c \
		src/shoot.c \
		src/sphere.c \
		src/plane.c

HEADERFILES := mlx2.h rays.h general.h

LIBFT := libft/libft.a

MLX := mlx/libmlx.dylib

all: $(NAME)
	
$(NAME) : $(SRCS) $(LIBFT) $(MLX)
		$(CC) $(CFLAGS) -o $@ $^
		@echo "$(GREEN)------------------ EXACUTABLE CREATED ------------------$(COLOUR_END)"

$(LIBFT) :
		$(MAKE) -C libft
		@echo "$(CYAN)-------------------- LIBFT COMPILED --------------------$(COLOUR_END)"

$(MLX) :
		$(MAKE) -C mlx && (test -e libmlx.dylib || ln -sf mlx/libmlx.dylib libmlx.dylib)
		@echo "$(CYAN)-------------------- MLX COMPILED --------------------$(COLOUR_END)"

clean :
		$(MAKE) clean -C libft
		@echo "$(RED)------------- LIBFT FILES DELETED -------------$(COLOUR_END)"

fclean:
		$(MAKE) fclean -C libft
		@echo "$(RED)------------- LIBFT FILES DELETED -------------$(COLOUR_END)"
		$(MAKE) clean -C mlx
		@echo "$(RED)------------- MLX FILES DELETED -------------$(COLOUR_END)"
		rm -f $(NAME)
		@echo "$(RED)------------- EXACUTABLE DELETED -------------$(COLOUR_END)"

re : fclean all

.PHONY: all, clean, fclean, re