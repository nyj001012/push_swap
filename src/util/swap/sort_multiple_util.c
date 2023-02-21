/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:16:16 by yena              #+#    #+#             */
/*   Updated: 2023/02/21 10:18:00 by yena             ###   ########.fr       */
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

void	put_max_node_to_top(t_stack *stack, int r_command, int rr_command)
{
	int		index_of_max_node;

	index_of_max_node = get_index_of_max_node(stack);
	if (index_of_max_node < stack->nodes_count / 2)
		rotate_max_node_to_head(stack, r_command);
	else
		rotate_max_node_to_head(stack, rr_command);
}

void	rotate_at_same_time(t_stack *a, t_stack *b,
							int *a_rotate, int *b_rotate)
{
	if (*a_rotate > 0 && *b_rotate > 0)
	{
		while (*a_rotate && *b_rotate)
		{
			rotate_a_and_b(a, b);
			(*a_rotate)--;
			(*b_rotate)--;
		}
	}
	else if (*a_rotate < 0 && *b_rotate < 0)
	{
		while (*a_rotate < 0 && *b_rotate < 0)
		{
			reverse_rotate_a_and_b(a, b);
			(*a_rotate)++;
			(*b_rotate)++;
		}
	}
}

void	rotate_each_stack(t_stack *a, t_stack *b, int *a_rotate, int *b_rotate)
{
	if (*a_rotate > 0)
	{
		while ((*a_rotate)-- != 0)
			rotate_a_or_b(a, RA);
	}
	else
	{
		while ((*a_rotate)++ != 0)
			reverse_rotate_a_or_b(a, RRA);
	}
	if (*b_rotate > 0)
	{
		while ((*b_rotate)-- != 0)
			rotate_a_or_b(b, RB);
	}
	else
	{
		while ((*b_rotate)++ != 0)
			reverse_rotate_a_or_b(b, RRB);
	}
}
