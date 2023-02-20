/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:28:47 by yena              #+#    #+#             */
/*   Updated: 2023/02/20 18:29:53 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_in_chunk(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
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
	int	nodes_count;

	i = 0;
	nodes_count = a->nodes_count;
	while (i++ < nodes_count)
		sort_three_in_chunk(a, b);
}

void	sort_whole_chunks(t_stack *a)
{
	int	rotate_count;

	rotate_count = get_rotate_count_with_min_max(a, a->min_node);
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
