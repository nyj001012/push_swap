/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:19:02 by yena              #+#    #+#             */
/*   Updated: 2023/02/20 12:01:26 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_when_min_is_middle(t_stack *a, t_node *max)
{
	if (a->head_node == max)
		rotate_a_or_b(a, RA);
	else
		swap_a_or_b(a, SA);
}

void	rotate_when_max_is_middle(t_stack *a, t_node *middle, t_node *min)
{
	if (middle->next == min)
		reverse_rotate_a_or_b(a, RRA);
	else
	{
		swap_a_or_b(a, SA);
		rotate_a_or_b(a, RA);
	}
}

void	sort_three(t_stack *a)
{
	t_node	*middle;
	t_node	*max;
	t_node	*min;

	middle = a->head_node->next;
	max = get_max_node(a);
	min = get_min_node(a);
	if (middle == min)
		rotate_when_min_is_middle(a, max);
	else if (middle == max)
		rotate_when_max_is_middle(a, middle, min);
	else
	{
		swap_a_or_b(a, SA);
		reverse_rotate_a_or_b(a, RRA);
	}
}
