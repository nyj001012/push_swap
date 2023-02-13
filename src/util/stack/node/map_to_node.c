/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:19:10 by yena              #+#    #+#             */
/*   Updated: 2023/02/12 17:18:15 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*map_to_node(t_node *node, int (*f)(int), void (*del)(int))
{
	t_node	*new_node;
	t_node	*head;

	if (!node || !f || !del)
		return (0);
	head = 0;
	while (node)
	{
		new_node = create_new_node(f(node->value));
		if (!new_node)
		{
			clear_stack(&head, del);
			break ;
		}
		add_tail_node(&head, new_node);
		node = node->next;
	}
	new_node = 0;
	return (head);
}
