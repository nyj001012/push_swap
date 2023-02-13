/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:52:07 by yena              #+#    #+#             */
/*   Updated: 2022/12/19 14:50:44 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	decimal_to_radix(unsigned long decimal, const char *radix_str,
					int radix)
{
	int	status;

	status = 0;
	if (!decimal)
		return (0);
	status = decimal_to_radix(decimal / radix, radix_str, radix);
	if (status == -1)
		return (-1);
	status += write(1, &radix_str[decimal % radix], 1);
	return (status);
}
