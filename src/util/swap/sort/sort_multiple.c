/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_multiple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:19:27 by yena              #+#    #+#             */
/*   Updated: 2023/02/19 15:57:35 by yena             ###   ########.fr       */
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

void	sort_multiple(t_stack *a, t_stack *b)
{
	while (a->nodes_count > 3)
	{
		put_max_node_to_top(a, RA, RRA);
		push_a_or_b(a, b, PB);
		a->max_node = get_max_node(a);
		a->min_node = get_min_node(a);
		b->max_node = get_max_node(b);
		b->min_node = get_min_node(b);
	}
	put_max_node_to_top(b, RB, RRB);
	sort_three(a);
	while (b->nodes_count)
		push_a_or_b(b, a, PA);
}
