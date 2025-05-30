# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 11:01:03 by maborges          #+#    #+#              #
#    Updated: 2025/01/24 17:07:17 by maborges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# My program name and libft var
NAME = libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc -Isrc

# Source files
SRCS =	src/ft_printf.c \
		src/ft_putnbr.c \
		src/ft_putnbr_unsigned.c \
		src/ft_putstr.c \
		src/ft_putadress.c \
		src/ft_puthex.c \
		src/ft_putchar.c \
		src/ft_puthex_min.c

# Object files (with paths accounted for)
OBJS = $(SRCS:%.c=%.o)

# Default rule to compile the program
all: $(NAME)

# Rule to link the object files into static lib
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to compile the source files into object files
# Fix for object paths
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# For make main (ensure main.c is in the same directory)
main: $(NAME) main.c
	$(CC) $(CFLAGS) main.c $(NAME) -o main

# Clean rule to remove object files
clean:
	rm -f $(OBJS)

# Fclean rule to remove object files and executable
fclean: clean
	rm -f $(NAME) main

# Rule to clean and recompile everything
re: fclean all

# Phony targets to prevent conflicts with files
.PHONY: all clean fclean re
