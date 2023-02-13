/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a_and_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:49:29 by yena              #+#    #+#             */
/*   Updated: 2023/02/13 16:18:52 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a_and_b(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_a_or_b(stack_a, RRR);
	reverse_rotate_a_or_b(stack_b, RRR);
	ft_printf("rrr");
}
