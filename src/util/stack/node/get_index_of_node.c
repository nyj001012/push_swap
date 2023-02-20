/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_of_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:21:24 by yena              #+#    #+#             */
/*   Updated: 2023/02/20 11:27:47 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_of_node(t_stack *stack, t_node *compare)
{
	t_node	*node;
	int		index;

	index = 0;
	if (!compare)
		return (-1);
	node = stack->head_node;
	while (index < stack->nodes_count)
	{
		if (node->value == compare->value)
			return (index);
		node = node->next;
		index++;
	}
	return (-1);
}

int	get_index_of_max_node(t_stack *stack)
{
	return (get_index_of_node(stack, stack->max_node));
}
