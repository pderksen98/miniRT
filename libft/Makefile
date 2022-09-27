# -*- Makefile -*-
NAME := libft.a
CFLAGS ?= -Wall -Wextra -Werror
SRCS := \
ft_atoi.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_strchr.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_tolower.c \
ft_toupper.c \
ft_strdup.c \
ft_calloc.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_strmapi.c \
ft_striteri.c \
ft_split_len.c \
ft_strdup_c.c \
ft_check_malloc.c 

OBJS := ${SRCS:%.c=%.o}

HEADERFILES := libft.h

all: $(NAME)
	
%.o: %.c $(HEADERFILES)
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(OBJS)
	ar -ru $(NAME) $^

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME) $^

re: fclean all

.PHONY: all, clean, fclean, re