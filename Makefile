NAME = push_swap

CC = cc
CFLAGS = -g -Wall -Werror -Wextra

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

INCLUDES = inc/

REMOVE = rm -f

SRC_DIR = src/

SRCS = \
$(SRC_DIR)algo_multi.c \
$(SRC_DIR)algo_three.c \
$(SRC_DIR)frees_and_errors.c \
$(SRC_DIR)init_stack_a.c \
$(SRC_DIR)main.c \
$(SRC_DIR)op_pushes.c \
$(SRC_DIR)op_reverse_rotates.c \
$(SRC_DIR)op_rotates.c \
$(SRC_DIR)op_swaps.c \
$(SRC_DIR)prepare_node_a.c \
$(SRC_DIR)prepare_node_b.c \
$(SRC_DIR)ps_utils_2.c \
$(SRC_DIR)ps_utils.c \
$(SRC_DIR)split.c \

OBJS = $(SRCS:.c=.o)

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RESET = \033[0m

all: $(FT_PRINTF) $(NAME)
	@echo "$(GREEN)Compilation successfully done!!$(RESET)"

$(FT_PRINTF):
	@echo "$(YELLOW)Compiling FT_PRINTF...$(RESET)"
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS)
	@echo "$(CYAN)Linking push_swap...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) -o $(NAME)
	@echo "$(GREEN)push_swap executable created successfully!$(RESET)"

%.o: %.c
	@echo "$(CYAN)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -I$(FT_PRINTF_DIR) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	$(REMOVE) $(OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	@echo "$(YELLOW)Removing executables...$(RESET)"
	$(REMOVE) $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
