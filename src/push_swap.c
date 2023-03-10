/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@studnet.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:56:13 by yena              #+#    #+#             */
/*   Updated: 2023/02/21 10:29:00 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char	**argv)
{
	char	**input;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		exit(0);
	input = make_input_lists(++argv);
	if (!input || !is_valid_input(input))
		throw_error();
	init_stack(&a, &b, input);
	free_pointers(input);
	if (is_sorted(&a))
	{
		destroy_stacks(&a, &b);
		exit(0);
	}
	push_swap(&a, &b);
	destroy_stacks(&a, &b);
	exit(0);
}
