/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_multiple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:19:27 by yena              #+#    #+#             */
/*   Updated: 2023/02/20 00:44:38 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_max_node_to_head(t_stack *a, int command)
{
	while (a->head_node != a->max_node)
	{
		if (command == RA)
			rotate_a_or_b(a, RA);
		else if (command == RRA)
			reverse_rotate_a_or_b(a, RRA);
		else if (command == RB)
			rotate_a_or_b(a, RB);
		else if (command == RRB)
			reverse_rotate_a_or_b(a, RRB);
	}
}

int		get_index_of_max_node(t_stack *stack)
{
	int		index;
	t_node	*node;

	index = 0;
	node = stack->head_node;
	while (node != stack->max_node && node->next)
	{
		node = node->next;
		index++;
	}
	return (index);
}

void	put_max_node_to_top(t_stack *stack, int r_command, int rr_command)
{
	int		index_of_max_node;

	index_of_max_node = get_index_of_max_node(stack);
	if (index_of_max_node < stack->nodes_count / 2)
		rotate_max_node_to_head(stack, r_command);
	else
		rotate_max_node_to_head(stack, rr_command);
}

void	set_pivots(t_stack *stack)
{
	int		i;
	t_node	*node;

	i = 0;
	node = stack->head_node;
	while (i < stack->nodes_count)
	{
		if (node->asc_order == stack->nodes_count / 3)
			stack->pivot1 = node;
		else if (node->asc_order == stack->nodes_count * 2 / 3)
			stack->pivot2 = node;
		node = node->next;
		i++;
	}
}

void	sort_three_in_chunk(t_stack *a, t_stack *b)
{
	if (a->head_node->value < a->pivot1->value)
	{
		push_a_or_b(a, b, PB);
		rotate_a_or_b(b, RB);
	}
	else if (a->head_node->value < a->pivot2->value)
		push_a_or_b(a, b, PB);
	else
		rotate_a_or_b(a, RA);
}

void	sort_chunks_divided_three(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i++ < a->nodes_count)
		sort_three_in_chunk(a, b);
}

int		get_index_of_node(t_stack *stack, t_node *compare)
{
	int	index;

	index = 0;
	if (!compare)
		return (-1);
	while (index < stack->nodes_count)
	{
		if (stack->head_node->value == compare->value)
			return (index);
		stack->head_node = stack->head_node->next;
		index++;
	}
	return (-1);
}

int		get_rotate_count_in_middle(t_stack *stack, int value_in_stack)
{
	t_node	*compare;
	int		count;

	count = 1;
	compare = stack->head_node;
	while (compare->next
		   && (value_in_stack > compare->value && value_in_stack < compare->next->value))
	{
		compare = compare->next;
		count++;
	}
	return (count);
}

int		get_rotate_count(t_stack *stack, int value_in_stack)
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

int	abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

bool	do_more_rotate(int *a_rotate, int *b_rotate, int a_count, int b_count)
{
	if (abs(*a_rotate) + abs(*b_rotate) > abs(a_count) + abs(b_count))
		return (true);
	return (false);
}

void	count_rotate(t_stack *stack_a, t_stack *stack_b, int *a_rotate, int *b_rotate)
{
	int	i;
	int	a_count;
	int	b_count;
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

void	rotate_at_same_time(t_stack *a, t_stack *b, int *a_rotate, int *b_rotate)
{
	if (*a_rotate > 0 && *b_rotate)
	{
		while (*(a_rotate)-- && *(b_rotate)--)
			rotate_a_and_b(a, b);
	}
	else
	{
		while (*(a_rotate)++ && *(b_rotate)++)
			reverse_rotate_a_and_b(a, b);
	}
}

void	rotate_each_stack(t_stack *a, t_stack *b, int *a_rotate, int *b_rotate)
{
	if (*a_rotate > 0)
	{
		while (*(a_rotate)--)
			rotate_a_or_b(a, RA);
	}
	else
	{
		while (*(a_rotate)++)
			reverse_rotate_a_or_b(a, RRA);
	}
	if (*b_rotate > 0)
	{
		while (*(b_rotate)--)
			rotate_a_or_b(b, RB);
	}
	else
	{
		while (*(b_rotate)++)
			reverse_rotate_a_or_b(b, RRB);
	}
}

void	sort_whole_chunks(t_stack *a)
{
	int	index_of_min_node;
	int	rotate_count;

	index_of_min_node = get_index_of_node(a, a->min_node);
	if (index_of_min_node > a->nodes_count / 2)
		rotate_count = (a->nodes_count - index_of_min_node) * -1;
	else
		rotate_count = index_of_min_node;
	if (rotate_count > 0)
	{
		while (rotate_count--)
			rotate_a_or_b(a, RA);
	}
	else
	{
		while (rotate_count++)
			reverse_rotate_a_or_b(a, RRA);
	}
}

void	sort_multiple(t_stack *a, t_stack *b)
{
	int	a_rotate;
	int	b_rotate;

	set_pivots(a);
	sort_chunks_divided_three(a, b);
	while (a->nodes_count > 3)
		push_a_or_b(a, b, PB);
	if (a->nodes_count == 2)
		sort_two(a);
	else if (a->nodes_count == 3)
		sort_three(a);
	while (b->nodes_count)
	{
		a_rotate = 0;
		b_rotate = 0;
		count_rotate(a, b, &a_rotate, &b_rotate);
		rotate_at_same_time(a, b, &a_rotate, &b_rotate);
		rotate_each_stack(a, b, &a_rotate, &b_rotate);
		push_a_or_b(b, a, PA);
	}
	sort_whole_chunks(a);
}
