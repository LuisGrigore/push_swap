CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I$(INC_DIR)

SRC_DIR	= src
INC_DIR	= includes
OBJ_DIR	= obj

SRCS	= $(SRC_DIR)/big_sort.c \
		  $(SRC_DIR)/cost.c \
		  $(SRC_DIR)/dll_node.c \
		  $(SRC_DIR)/do_cheapest.c \
		  $(SRC_DIR)/double_link_list_basic_ops.c \
		  $(SRC_DIR)/double_link_list.c \
		  $(SRC_DIR)/double_link_list_ops.c \
		  $(SRC_DIR)/double_stack.c \
		  $(SRC_DIR)/double_stack_position.c \
		  $(SRC_DIR)/double_stack_push_ops.c \
		  $(SRC_DIR)/double_stack_reverse_rotate_ops.c \
		  $(SRC_DIR)/double_stack_rotate_ops.c \
		  $(SRC_DIR)/double_stack_sort.c \
		  $(SRC_DIR)/double_stack_swap_ops.c \
		  $(SRC_DIR)/input_checker.c \
		  $(SRC_DIR)/main.c \
		  $(SRC_DIR)/node_data.c \
		  $(SRC_DIR)/target.c \
		  $(SRC_DIR)/tiny_sort.c \
		  $(SRC_DIR)/util.c

OBJS	= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME	= push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
