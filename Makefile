NAME = push_swap

CC = cc
CFLAGS = -g -Wall -Werror -Wextra

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = inc/

REMOVE = rm -f

SRC_DIR = src/

SRCS = \
$(SRC_DIR)main.c \
$(SRC_DIR)map_parsing.c \
$(SRC_DIR)map_parsing_utils.c \
$(SRC_DIR)game_loop.c \
$(SRC_DIR)load_img.c \
$(SRC_DIR)frees_and_errors.c \

OBJS = $(SRCS:.c=.o)

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RESET = \033[0m

all: $(LIBFT) $(NAME)
	@echo "$(GREEN)Compilation successfully done!!$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@echo "$(CYAN)Linking push_swap...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)push_swap executable created successfully!$(RESET)"

%.o: %.c
	@echo "$(CYAN)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	$(REMOVE) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(YELLOW)Removing executables...$(RESET)"
	$(REMOVE) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
