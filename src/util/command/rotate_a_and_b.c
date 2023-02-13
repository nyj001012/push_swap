/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_and_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:40:44 by yena              #+#    #+#             */
/*   Updated: 2023/02/13 16:16:55 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_and_b(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a_or_b(stack_a, RR);
	rotate_a_or_b(stack_b, RR);
	ft_printf("rr");
}
