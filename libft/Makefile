# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 16:23:58 by maborges          #+#    #+#              #
#    Updated: 2025/05/21 17:15:43 by maborges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# My program name variable
NAME = libft.a

#Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

#Includes
INCLUDE = -I . -I gnl -I./ft_printf/inc

#Source files
SRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \

#Libft Source Files
GNL_DIR = gnl
GNL_SRCS = $(GNL_DIR)/get_next_line.c \

#ft_printf Source Files
FT_PRINTF_DIR = ft_printf/src
FT_PRINTF_SRCS = $(FT_PRINTF_DIR)/ft_printf.c \
	$(FT_PRINTF_DIR)/ft_putadress.c \
	$(FT_PRINTF_DIR)/ft_putchar.c \
	$(FT_PRINTF_DIR)/ft_puthex_m.c \
	$(FT_PRINTF_DIR)/ft_puthex_min.c \
	$(FT_PRINTF_DIR)/ft_puthex.c \
	$(FT_PRINTF_DIR)/ft_putnbr_unsigned.c \
	$(FT_PRINTF_DIR)/ft_putnbr.c \
	$(FT_PRINTF_DIR)/ft_putstr.c \

# Object files
OBJS = $(SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)

#Default rule to compile the program
all: $(NAME)

#Rule to link the object files into executable, create static lib and update the index of static lib
$(NAME): $(OBJS) $(GNL_OBJS) $(FT_PRINTF_OBJS)
	ar rcs $(NAME) $(OBJS) $(GNL_OBJS) $(FT_PRINTF_OBJS)

#Rule to compile the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(FT_PRINTF_DIR)/%.o: $(FT_PRINTF_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#For make main
main: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o main

#Clean rule to remove object files
clean:
	rm -f $(OBJS) $(GNL_OBJS) $(FT_PRINTF_OBJS)

#Fclean rule to remove object files and executable
fclean: clean
	rm -f $(NAME)

#Rule to clean and recompile everything
re: fclean all

#Phony targets to prevent conflicts with files
.PHONY: all clean fclean re
