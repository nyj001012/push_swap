/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:33:22 by yena              #+#    #+#             */
/*   Updated: 2023/02/15 14:56:28 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_median_node(t_stack *stack)
{
	t_node	*current;
	int		median_index;

	current = stack->head_node;
	median_index = get_nodes_count(stack) / 2;
	while (median_index--)
		current = current->next;
	return (current);
}
