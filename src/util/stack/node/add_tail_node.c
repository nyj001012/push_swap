/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:05:43 by yena              #+#    #+#             */
/*   Updated: 2023/02/12 17:10:16 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_tail_node(t_node **current, t_node *new)
{
	t_node	*last;

	if (!*current || !new)
		return ;
	else if (!*current && new)
	{
		*current = new;
		return ;
	}
	last = get_tail_node(*current);
	last->next = new;
}
