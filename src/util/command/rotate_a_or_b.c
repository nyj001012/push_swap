/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_or_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:32:07 by yena              #+#    #+#             */
/*   Updated: 2023/02/14 10:34:19 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_or_b(t_stack *stack, int command)
{
	t_node	*temp;
	t_node	*current;

	if (!stack->head_node)
		return ;
	temp = stack->head_node;
	current = get_tail_node(stack->head_node);
	current->next = temp;
	stack->head_node = stack->head_node->next;
	temp->next = NULL;
	if (command == RA)
		ft_printf("ra\n");
	else if (command == RB)
		ft_printf("rb\n");
}
