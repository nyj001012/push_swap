/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_multiple_counter_util.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:31:24 by yena              #+#    #+#             */
/*   Updated: 2023/02/20 11:40:36 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rotate_count_in_middle(t_stack *stack, int value_in_stack)
{
	t_node	*compare;
	int		count;

	count = 1;
	compare = stack->head_node;
	while (compare->next
		&& (value_in_stack > compare->value
			&& value_in_stack < compare->next->value))
	{
		compare = compare->next;
		count++;
	}
	return (count);
}

void	count_rotate(t_stack *stack_a, t_stack *stack_b,
					int *a_rotate, int *b_rotate)
{
	int		i;
	int		a_count;
	int		b_count;
	t_node	*node_b;

	i = 0;
	a_count = 0;
	b_count = 0;
	node_b = stack_b->head_node;
	while (i < stack_b->nodes_count)
	{
		a_count = get_rotate_count(stack_a, node_b->value);
		if (i > (stack_b->nodes_count + 1) / 2)
			b_count = (stack_b->nodes_count - i) * -1;
		else
			b_count = i;
		node_b = node_b->next;
		if (i == 0 || do_more_rotate(a_rotate, b_rotate, a_count, b_count))
		{
			*a_rotate = a_count;
			*b_rotate = b_count;
		}
		i++;
	}
}

int	get_rotate_count(t_stack *stack, int value_in_stack)
{
	t_node	*compare;
	t_node	*min_node;
	int		count;

	min_node = get_min_node(stack);
	if (value_in_stack < min_node->value)
	{
		compare = min_node;
		count = get_index_of_node(stack, compare);
	}
	else if (value_in_stack > stack->max_node->value)
	{
		compare = stack->max_node;
		count = get_index_of_node(stack, compare);
	}
	else
		count = get_rotate_count_in_middle(stack, value_in_stack);
	if (count > stack->nodes_count / 2)
		count = (stack->nodes_count - count) * -1;
	return (count);
}

bool	do_more_rotate(int *a_rotate, int *b_rotate, int a_count, int b_count)
{
	if (my_abs(*a_rotate) + my_abs(*b_rotate)
		> my_abs(a_count) + my_abs(b_count))
		return (true);
	return (false);
}
