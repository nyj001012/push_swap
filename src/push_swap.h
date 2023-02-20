/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@studnet.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:41:33 by yena              #+#    #+#             */
/*   Updated: 2023/02/20 11:45:36 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

typedef struct s_node
{
	int					value;
	int					asc_order;
	struct s_node		*next;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head_node;
	struct s_node	*max_node;
	struct s_node	*min_node;
	struct s_node	*pivot1;
	struct s_node	*pivot2;
	int				nodes_count;
}	t_stack;

enum e_commands
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
};

/*------------------ POINTER_UTIL_C -------------------*/
void	free_pointers(char **ptrs);

/*------------------- ERROR_UTIL_C --------------------*/
void	throw_error(void);

/*------------------- INPUT_UTIL_C --------------------*/
size_t	get_input_size(char **argv);
char	**make_input_lists(char **argv);

/*----------------- INTEGER_UTIL_C --------------------*/
int		my_abs(int num);

/*---------------- INPUT_VALIDATION_C -----------------*/
bool	is_valid_input(char **input);
bool	is_underflow(char *string);
bool	is_overflow(char *string);
bool	is_sorted(t_stack *a);

/*--------------------- NODE_UTIL ---------------------*/
void	add_head_node(t_node **current, t_node *new);
void	add_tail_node(t_node **current, t_node *new);
t_node	*create_new_node(int value);
void	delete_one_node(t_node *node, void (*del)(int *));
t_node	*get_max_node(t_stack *stack);
t_node	*get_min_node(t_stack *stack);
t_node	*get_median_node(t_stack *stack);
int		get_nodes_count(t_stack *stack);
t_node	*get_tail_node(t_node *node);
t_node	*map_to_node(t_node *node, int (*f)(int *), void (*del)(int *));
void	node_iter(t_node *node, void (*f)(int *));
int		get_index_of_node(t_stack *stack, t_node *compare);
int		get_index_of_max_node(t_stack *stack);

/*--------------------- STACK_UTIL --------------------*/
void	clear_stack(t_node **current, void (*del)(int *));
void	init_stack(t_stack *stack_a, t_stack *stack_b, char **input);
void	set_ascending_order_of_nodes(t_stack *stack);
bool	is_sorted(t_stack *stack);
void	destroy_stacks(t_stack *a, t_stack *b);
void	set_pivots(t_stack *stack);

/*--------------------- PRINT_UTIL --------------------*/
void	print_command(char *command);

/*---------------------- COMMAND ----------------------*/
void	swap_a_or_b(t_stack *stack, int command);
void	swap_a_and_b(t_stack *stack_a, t_stack *stack_b);
void	push_a_or_b(t_stack *stack_from, t_stack *stack_to, int command);
void	rotate_a_or_b(t_stack *stack, int command);
void	rotate_a_and_b(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_a_or_b(t_stack *stack, int command);
void	reverse_rotate_a_and_b(t_stack *stack_a, t_stack *stack_b);

/*--------------------- SWAP_UTIL ---------------------*/
void	push_swap(t_stack *a, t_stack *b);

/*--------------------- SORT_UTIL ---------------------*/
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_multiple(t_stack *a, t_stack *b);

/*-------------------- SORT_CHUNK ---------------------*/
void	sort_three_in_chunk(t_stack *a, t_stack *b);
void	sort_chunks_divided_three(t_stack *a, t_stack *b);
void	sort_whole_chunks(t_stack *a);

/*----------------- SORT_MULTIPLE_UTIL ----------------*/
void	rotate_max_node_to_head(t_stack *a, int command);
void	put_max_node_to_top(t_stack *stack, int r_command, int rr_command);
void	rotate_at_same_time(t_stack *a, t_stack *b,
			int *a_rotate, int *b_rotate);
void	rotate_each_stack(t_stack *a, t_stack *b,
			int *a_rotate, int *b_rotate);

/*------------- SORT_MULTIPLE_COUNTER_UTIL ------------*/
void	count_rotate(t_stack *stack_a, t_stack *stack_b,
			int *a_rotate, int *b_rotate);
int		get_rotate_count_in_middle(t_stack *stack, int value_in_stack);
int		get_rotate_count(t_stack *stack, int value_in_stack);
bool	do_more_rotate(int *a_rotate, int *b_rotate, int a_count, int b_count);

#endif //PUSH_SWAP_PUSH_SWAP_H
