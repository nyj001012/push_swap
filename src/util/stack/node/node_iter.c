/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:16:46 by yena              #+#    #+#             */
/*   Updated: 2023/02/12 17:19:03 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_iter(t_node *node, void (*f)(int))
{
	t_node	*temp;

	if (!node || !f)
		return ;
	temp = node;
	while (temp)
	{
		f(temp->value);
		temp = temp->next;
	}
}
