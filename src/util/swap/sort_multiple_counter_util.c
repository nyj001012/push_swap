/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_multiple_counter_util.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:31:24 by yena              #+#    #+#             */
/*   Updated: 2023/02/21 10:09:34 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rotate_count_in_middle(t_stack *stack, int value_in_stack)
{
	t_node	*compare;
	int		count;

	count = 1;
	compare = stack->head_node;
	while (compare->next)
	{
		if (value_in_stack > compare->value
			&& value_in_stack < compare->next->value)
			break ;
		compare = compare->next;
		count++;
	}
	if (count >= (stack->nodes_count + 1) / 2)
		count = (stack->nodes_count - count) * -1;
	return (count);
}

int	get_rotate_count_with_min_max(t_stack *stack, t_node *compare)
{
	int		count;
	t_node	*node;

	if (compare == get_max_node(stack))
		count = 1;
	else
		count = 0;
	node = stack->head_node;
	while (node->next)
	{
		if (node->value == compare->value)
			break ;
		node = node->next;
		count++;
	}
	if (count >= (stack->nodes_count + 1) / 2)
		count = (stack->nodes_count - count) * -1;
	return (count);
}

int	get_rotate_count(t_stack *stack, int value_in_stack)
{
	t_node	*max_node;
	t_node	*min_node;
	int		count;

	max_node = get_max_node(stack);
	min_node = get_min_node(stack);
	if (value_in_stack < min_node->value)
		count = get_rotate_count_with_min_max(stack, min_node);
	else if (value_in_stack > max_node->value)
		count = get_rotate_count_with_min_max(stack, max_node);
	else
		count = get_rotate_count_in_middle(stack, value_in_stack);
	if (count >= (stack->nodes_count + 1) / 2)
		count = (stack->nodes_count - count) * -1;
	return (count);
}

bool	do_more_rotate(int *a_rotate, int *b_rotate, int a_count, int b_count)
{
	int	old_rotate_count;
	int	new_rotate_count;

	old_rotate_count = my_abs(*a_rotate) + my_abs(*b_rotate);
	new_rotate_count = my_abs(a_count) + my_abs(b_count);
	if (old_rotate_count > new_rotate_count)
		return (true);
	return (false);
}

void	count_rotate(t_stack *stack_a, t_stack *stack_b,
					int *a_rotate, int *b_rotate)
{
	int		i;
	int		a_count;
	int		b_count;
	t_node	*node_b;

	i = 0;
	node_b = stack_b->head_node;
	while (i < stack_b->nodes_count)
	{
		a_count = get_rotate_count(stack_a, node_b->value);
		if (i >= (stack_b->nodes_count + 1) / 2)
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
