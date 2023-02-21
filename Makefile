NAME = push_swap

SRC_DIR = src
SRC_RAW = push_swap.c
SRCS = ${addprefix $(SRC_DIR)/, $(SRC_RAW)}
OBJS = ${SRCS:.c=.o}

UTILS_NAME = util/pointer_util.c\
			 util/error_util.c\
			 util/print_util.c\
			 util/input_util.c\
			 util/integer_util.c\
			 util/validation/input_validation.c\
			 util/validation/integer_validation.c\
			 util/stack/clear_stack.c\
			 util/stack/init_stack.c\
			 util/stack/is_sorted.c\
			 util/stack/set_pivots.c\
			 util/stack/destroy_stacks.c\
			 util/stack/node/add_head_node.c\
			 util/stack/node/add_tail_node.c\
			 util/stack/node/create_new_node.c\
			 util/stack/node/delete_one_node.c\
			 util/stack/node/get_tail_node.c\
			 util/stack/node/get_nodes_count.c\
			 util/stack/node/map_to_node.c\
			 util/stack/node/node_iter.c\
			 util/stack/node/get_max_node.c\
			 util/stack/node/get_min_node.c\
			 util/stack/node/get_median_node.c\
			 util/stack/node/get_index_of_node.c\
			 util/command/push_a_or_b.c\
			 util/command/reverse_rotate_a_and_b.c\
			 util/command/reverse_rotate_a_or_b.c\
			 util/command/rotate_a_and_b.c\
			 util/command/rotate_a_or_b.c\
			 util/command/swap_a_and_b.c\
			 util/command/swap_a_or_b.c\
			 util/swap/swap_util.c\
			 util/swap/sort_multiple_counter_util.c\
			 util/swap/sort_multiple_util.c\
			 util/swap/sort/sort_two.c\
			 util/swap/sort/sort_three.c\
			 util/swap/sort/sort_multiple.c\
			 util/swap/sort/sort_depending_on_pivots.c
UTILS = ${addprefix $(SRC_DIR)/, $(UTILS_NAME)}
UTILS_OBJS = ${UTILS:.c=.o}

TEST_DIR  = test
TEST_RAWS = unit/unit_test.c\
			unit/push_a_or_b.c\
			unit/reverse_rotate_a_or_b.c\
			unit/reverse_rotate_a_and_b.c\
			unit/rotate_a_or_b.c\
			unit/rotate_a_and_b.c\
			unit/swap_a_or_b.c
TEST_SRCS = ${addprefix $(TEST_DIR)/, $(TEST_RAWS)}
TEST_OBJS = ${TEST_SRCS:.c=.o}
TESTER    = push_swap.test

LIBFT_DIR = libft
LIBFT = libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF = libftprintf.a

GNL_DIR = get_next_line
GNL = get_next_line.c
GNL_OBJS = ${GNL:.c=.o}

INC = -I $(SRC_DIR) -I $(GNL_DIR) -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) -I $(TEST_DIR)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RMF = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(UTILS_OBJS) $(GNL_DIR)/$(GNL_OBJS)
	make -C $(LIBFT_DIR)
	make -C $(FT_PRINTF_DIR)

	$(CC) $(CFLAGS) $(UTILS_OBJS)\
					$(LIBFT_DIR)/$(LIBFT)\
					$(FT_PRINTF_DIR)/$(FT_PRINTF)\
					$(GNL_DIR)/$(GNL_OBJS)\
  					$(OBJS)\
					$(INC)\
					-o $(NAME)

%.o:%.c
	${CC} ${CFLAGS} $(INC) -c $< -o $@

test: $(TESTER)

$(TESTER): $(TEST_OBJS) $(UTILS_OBJS) $(GNL_DIR)/$(GNL_OBJS)
	make -C $(LIBFT_DIR)
	make -C $(FT_PRINTF_DIR)

	$(CC) $(CFLAGS) $(UTILS_OBJS)\
					$(LIBFT_DIR)/$(LIBFT)\
					$(FT_PRINTF_DIR)/$(FT_PRINTF)\
					$(GNL_DIR)/$(GNL_OBJS)\
  					$(TEST_OBJS)\
					$(INC)\
					$(TEST_INC)\
					-o $(TESTER)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean
	$(RMF) $(OBJS) $(UTILS_OBJS) $(GNL_DIR)/$(GNL_OBJS) $(TEST_OBJS)

fclean: clean
	$(RMF) $(NAME) $(LIBFT_DIR)/$(LIBFT) $(FT_PRINTF_DIR)/$(FT_PRINTF) $(TESTER)

re: fclean all

.PHONY: all clean fclean re