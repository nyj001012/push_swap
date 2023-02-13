/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:44:33 by yena              #+#    #+#             */
/*   Updated: 2023/02/12 17:51:44 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->head_node)
		return (false);
	current = stack->head_node;
	while (current->next)
	{
		if (current->value < current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}
