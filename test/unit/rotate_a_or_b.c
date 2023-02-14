/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_or_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:32:07 by yena              #+#    #+#             */
/*   Updated: 2023/02/14 13:40:29 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_or_b_test(void)
{
	t_stack	a;
	t_stack	b;
	t_node	*a_head_node;
	t_node	*b_head_node;
	char	**argv;

	a_head_node = NULL;
	b_head_node = NULL;
	argv = ft_split("0 -1 3 2 4 1", ' ');
	init_stack(&a, &b, argv);
	ft_printf("============ command: ra ============\n");
	ft_printf("stack a: 1 4 2 3 -1 0 \tstack b: \n");
	ft_printf("from rotate_a_or_b(): ");
	rotate_a_or_b(&a, RA);
	ft_printf("expected => stack a: 4 2 3 -1 0 1 \tstack b: \n");
	ft_printf("result   => stack a: ");
	a_head_node = a.head_node;
	while (a_head_node)
	{
		ft_printf("%d ", a_head_node->value);
		a_head_node = a_head_node->next;
	}
	ft_printf("\tstack b: ");
	b_head_node = b.head_node;
	while (b_head_node)
	{
		ft_printf("%d ", b_head_node->value);
		b_head_node = b_head_node->next;
	}

	ft_printf("\n\n============ command: rb ============\n");
	ft_printf("stack a: 4 2 3 -1 0 1 \tstack b: \n");
	ft_printf("from rotate_a_or_b(): must do nothing\n");
	rotate_a_or_b(&b, RB);
	ft_printf("expected => stack a: 4 2 3 -1 0 1 \tstack b: \n");
	ft_printf("result   => stack a: ");
	a_head_node = a.head_node;
	while (a_head_node)
	{
		ft_printf("%d ", a_head_node->value);
		a_head_node = a_head_node->next;
	}
	ft_printf("\tstack b: ");
	b_head_node = b.head_node;
	while (b_head_node)
	{
		ft_printf("%d ", b_head_node->value);
		b_head_node = b_head_node->next;
	}
	destroy_stacks(&a, &b);
	free_pointers(argv);
}
