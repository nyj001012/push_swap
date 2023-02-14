/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_or_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:13:27 by yena              #+#    #+#             */
/*   Updated: 2023/02/14 10:34:37 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_or_b(t_stack *stack, int command)
{
	t_node	*temp;

	if (!stack->head_node || !stack->head_node->next)
		return ;
	temp = stack->head_node;
	stack->head_node = stack->head_node->next;
	temp->next = stack->head_node->next;
	stack->head_node->next = temp;
	if (command == SA)
		ft_printf("sa\n");
	else if (command == SB)
		ft_printf("sb\n");
}
