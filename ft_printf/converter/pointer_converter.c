/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:03:59 by yena              #+#    #+#             */
/*   Updated: 2022/12/19 16:17:09 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	convert_to_address(unsigned long decimal_addr)
{
	if (!decimal_addr)
		return (write(1, "0x0", 3));
	else
		write(1, "0x", 2);
	return (decimal_to_radix((long long)decimal_addr, S_HEXA_SET,
			ft_strlen(S_HEXA_SET)) + 2);
}
