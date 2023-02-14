/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_and_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:26:48 by yena              #+#    #+#             */
/*   Updated: 2023/02/13 16:19:11 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_and_b(t_stack *stack_a, t_stack *stack_b)
{
	swap_a_or_b(stack_a, SS);
	swap_a_or_b(stack_b, SS);
	ft_printf("ss");
}
