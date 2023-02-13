/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@studnet.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:57:22 by yena              #+#    #+#             */
/*   Updated: 2023/02/06 13:50:53 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	end_with_ok(void)
{
	ft_putstr_fd("OK\n", STDOUT_FILENO);
	exit(0);
}

void	end_with_ko(void)
{
	ft_putstr_fd("KO\n", STDOUT_FILENO);
	exit(0);
}
