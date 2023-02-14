/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:19:39 by yena              #+#    #+#             */
/*   Updated: 2023/02/14 13:55:26 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	push_a_or_b_test();
	ft_printf("\n\n");
	reverse_rotate_a_or_b_test();
	ft_printf("\n\n");
	reverse_rotate_a_and_b_test();
	ft_printf("\n\n");
	rotate_a_or_b_test();
	ft_printf("\n\n");
	rotate_a_and_b_test();
	ft_printf("\n\n");
	swap_a_or_b_test();
	ft_printf("\n\n");
	return (0);
}
