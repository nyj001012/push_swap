/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_multiple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:19:27 by yena              #+#    #+#             */
/*   Updated: 2023/02/20 22:05:35 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_multiple(t_stack *a, t_stack *b)
{
	int	a_rotate;
	int	b_rotate;

	set_pivots(a);
	sort_chunks_divided_three(a, b);
	while (a->nodes_count > 3 && !is_sorted(a))
		push_a_or_b(a, b, PB);
	if (a->nodes_count == 2 && !is_sorted(a))
		sort_two(a);
	else if (a->nodes_count == 3 && !is_sorted(a))
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
