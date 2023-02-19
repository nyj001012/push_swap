/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:58:02 by yena              #+#    #+#             */
/*   Updated: 2023/02/15 15:58:33 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_head_node(t_node **current, t_node *new)
{
	if (!new)
		return ;
	if (!current || !*current)
	{
		*current = new;
		return ;
	}
	new->next = *current;
	*current = new;
}
