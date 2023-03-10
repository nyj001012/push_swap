/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:10:03 by yena              #+#    #+#             */
/*   Updated: 2023/02/19 15:19:21 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_node **current, void (*del)(int *))
{
	t_node	*temp;

	while (current && *current)
	{
		temp = (*current)->next;
		delete_one_node(*current, del);
		*current = temp;
	}
	*current = 0;
}
