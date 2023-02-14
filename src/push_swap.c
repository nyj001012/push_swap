/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@studnet.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:56:13 by yena              #+#    #+#             */
/*   Updated: 2023/02/14 15:04:20 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char	**argv)
{
	char	**input;
	t_stack a;
	t_stack b;

	(void)b;
	if (argc == 1)
		throw_error();
	input = make_input_lists(++argv);
	if (!input || !is_valid_input(input))
		throw_error();
	init_stack(&a, &b, argv);
	free_pointers(input);
	if (is_sorted(&a))
	{
		destroy_stacks(&a, &b);
		exit(0);
	}
	// TODO => do swap
//	push_swap(&a, &b);
	destroy_stacks(&a, &b);
	exit(0);
}
