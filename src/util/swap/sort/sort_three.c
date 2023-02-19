/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:19:02 by yena              #+#    #+#             */
/*   Updated: 2023/02/20 00:28:55 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	t_node	*middle;
	t_node	*max;
	t_node	*min;

	middle = a->head_node->next;
	max = get_max_node(a);
	min = get_min_node(a);
	if (middle == min)
	{
		if (a->head_node == max)
			rotate_a_or_b(a, RA);
		else
			swap_a_or_b(a, SA);
	}
	else if (middle == max)
	{
		if (middle->next == min)
			reverse_rotate_a_or_b(a, RRA);
		else
		{
			swap_a_or_b(a, SA);
			rotate_a_or_b(a, RA);
		}
	}
	else
	{
		swap_a_or_b(a, SA);
		reverse_rotate_a_or_b(a, RRA);
	}
}
