/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:38:05 by yena              #+#    #+#             */
/*   Updated: 2023/02/19 14:11:56 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack_a, t_stack *stack_b, char **input)
{
	int		value;
	t_node	*node;

	stack_a->head_node = NULL;
	while (*input)
	{
		value = ft_atoi(*input);
		node = create_new_node(value);
		add_head_node(&stack_a->head_node, node);
		input++;
	}
	stack_a->max_node = get_max_node(stack_a);
	stack_a->min_node = get_min_node(stack_a);
	stack_a->nodes_count = get_nodes_count(stack_a);
	stack_b->head_node = NULL;
	stack_b->nodes_count = 0;
	stack_b->max_node = NULL;
	stack_b->min_node = NULL;
}
