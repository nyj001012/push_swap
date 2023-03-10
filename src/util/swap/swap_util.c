/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:13:39 by yena              #+#    #+#             */
/*   Updated: 2023/02/15 13:12:13 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->nodes_count == 2)
		sort_two(a);
	else if (a->nodes_count == 3)
		sort_three(a);
	else
		sort_multiple(a, b);
}
