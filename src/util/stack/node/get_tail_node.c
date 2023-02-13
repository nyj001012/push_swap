/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:03:43 by yena              #+#    #+#             */
/*   Updated: 2023/02/12 17:14:59 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_tail_node(t_node *node)
{
	t_node	*tail;

	tail = node;
	if (!node)
		return (0);
	while (tail->next)
		tail = tail->next;
	return (tail);
}
