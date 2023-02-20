/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:28:47 by yena              #+#    #+#             */
/*   Updated: 2023/02/20 11:29:37 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
