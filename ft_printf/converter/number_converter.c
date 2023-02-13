/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:02:43 by yena              #+#    #+#             */
/*   Updated: 2022/12/19 16:17:57 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	convert_to_number(long long src)
{
	char	*formatted;
	int		length;

	formatted = ft_itoa(src);
	if (!formatted)
		return (-1);
	length = convert_to_string(formatted);
	free(formatted);
	return (length);
}

int	convert_to_hexa(unsigned int decimal, char conversion)
{
	if (!decimal)
		return (write(1, "0", 1));
	if (conversion == 'X')
		return (decimal_to_radix((unsigned long)decimal, L_HEXA_SET,
				ft_strlen(L_HEXA_SET)));
	else
		return (decimal_to_radix((unsigned long)decimal, S_HEXA_SET,
				ft_strlen(S_HEXA_SET)));
}
