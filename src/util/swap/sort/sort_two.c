/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:18:28 by yena              #+#    #+#             */
/*   Updated: 2023/02/14 15:29:10 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	t_node	*head_node;

	head_node = a->head_node;
	if (head_node->value > head_node->next->value)
		swap_a_or_b(a, SA);
	else
		return ;
}
