/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:19:02 by yena              #+#    #+#             */
/*   Updated: 2023/02/19 16:10:32 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	t_node	*middle;

	middle = a->head_node->next;
	if (middle == a->min_node)
	{
		if (a->head_node == a->min_node)
			reverse_rotate_a_or_b(a, RRA);
		else
		{
			reverse_rotate_a_or_b(a, RRA);
			swap_a_or_b(a, SA);
		}
	}
	else if (middle == a->max_node)
	{
		if (middle->next == a->max_node)
			swap_a_or_b(a, SA);
		else
			rotate_a_or_b(a, RA);
	}
	else
	{
		swap_a_or_b(a, SA);
		reverse_rotate_a_or_b(a, RRA);
	}
}
