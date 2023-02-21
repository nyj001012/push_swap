/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:28:47 by yena              #+#    #+#             */
/*   Updated: 2023/02/21 11:53:53 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_smaller_than_pivot2(t_stack *a, t_stack *b)
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

void	sort_bigger_than_pivots(t_stack *a, t_stack *b)
{
	int	i;
	int	nodes_count;

	i = 0;
	nodes_count = a->nodes_count;
	while (i++ < nodes_count)
		pb_smaller_than_pivot2(a, b);
}
