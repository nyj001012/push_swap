/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pivots.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:20:18 by yena              #+#    #+#             */
/*   Updated: 2023/02/20 18:16:08 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
