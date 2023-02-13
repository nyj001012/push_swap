/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:54:42 by yena              #+#    #+#             */
/*   Updated: 2023/02/13 16:24:46 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_value(int *value)
{
	*value = 0;
}

void	destroy_stacks(t_stack *a, t_stack *b)
{
	if (a->head_node)
		clear_stack(&a->head_node, clear_value);
	if (b->head_node)
		clear_stack(&b->head_node, clear_value);
}