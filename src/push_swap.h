/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@studnet.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:41:33 by yena              #+#    #+#             */
/*   Updated: 2023/02/14 15:25:25 by yena             ###   ########.fr       */
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
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head_node;
	struct s_node	*max_node;
	struct s_node	*min_node;
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

/*------------------- ERROR_UTIL_C --------------------*/
void	free_pointers(char **ptrs);

/*------------------- ERROR_UTIL_C --------------------*/
void	throw_error(void);

/*------------------- INPUT_UTIL_C --------------------*/
size_t	get_input_size(char **argv);
char	**make_input_lists(char **argv);

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
int 	get_nodes_count(t_stack *stack);
t_node	*get_tail_node(t_node *node);
t_node	*map_to_node(t_node *node, int (*f)(int *), void (*del)(int *));
void	node_iter(t_node *node, void (*f)(int *));

/*--------------------- STACK_UTIL --------------------*/
void	clear_stack(t_node **current, void (*del)(int *));
void	init_stack(t_stack *stack_a, t_stack *stack_b, char **input);
bool	is_sorted(t_stack *stack);
void	destroy_stacks(t_stack *a, t_stack *b);

/*--------------------- PRINT_UTIL --------------------*/
void	print_command(char *command);

/*---------------------- COMMAND ----------------------*/
void	swap_a_or_b(t_stack *stack, int command); // Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
void	swap_a_and_b(t_stack *stack_a, t_stack *stack_b); // sa and sb at the same time.
void	push_a_or_b(t_stack *stack_from, t_stack *stack_to, int command); // Take the first element at the top of b/a and put it at the top of a/b. Do nothing if b/a is empty.
void	rotate_a_or_b(t_stack *stack, int command); // Shift up all elements of stack a/b by 1. The first element becomes the last one.
void	rotate_a_and_b(t_stack *stack_a, t_stack *stack_b); // ra and rb at the same time.
void	reverse_rotate_a_or_b(t_stack *stack, int command); // Shift down all elements of stack a/b by 1.
void	reverse_rotate_a_and_b(t_stack *stack_a, t_stack *stack_b); // rra and rrb at the same time.

/*--------------------- SWAP_UTIL ---------------------*/
void	push_swap(t_stack *a, t_stack *b);

/*--------------------- SORT_UTIL ---------------------*/
void	sort_two(t_stack *a);
void	sort_three(t_stack *a, t_stack *b);
void	sort_multiple(t_stack *a, t_stack *b);

#endif //PUSH_SWAP_PUSH_SWAP_H
