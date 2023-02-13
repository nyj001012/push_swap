/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a_or_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:42:10 by yena              #+#    #+#             */
/*   Updated: 2023/02/13 16:15:54 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a_or_b(t_stack *stack, int command)
{
	t_node	*tail_node;
	t_node	*current;
	int		nodes_count;

	if (!stack->head_node || !stack->head_node->next)
		return ;
	tail_node = get_tail_node(stack->head_node);
	tail_node->next = stack->head_node;
	current = stack->head_node;
	nodes_count = get_nodes_count(stack);
	while (--nodes_count)
		current = current->next;
	current->next = NULL;
	if (command == RRA)
		ft_printf("rra");
	else if (command == RRB)
		ft_printf("rrb");
}
