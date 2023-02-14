/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_or_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:27:41 by yena              #+#    #+#             */
/*   Updated: 2023/02/14 10:41:53 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_or_b(t_stack *stack_from, t_stack *stack_to, int command) {
	t_node *temp;

	if (!stack_from->head_node)
		return;
	temp = stack_from->head_node;
	stack_from->head_node = stack_from->head_node->next;
	add_head_node(&stack_to->head_node, temp);
	if (command == PA)
		ft_printf("pa\n");
	else if (command == PB)
		ft_printf("pb\n");
}
