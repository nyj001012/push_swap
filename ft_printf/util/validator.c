/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:23:48 by yena              #+#    #+#             */
/*   Updated: 2022/12/14 19:47:12 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

boolean	is_valid(const char *format, va_list ap)
{
	va_list	ap_copy;
	int		i;
	int		conversion_count;

	va_copy(ap_copy, ap);
	conversion_count = 0;
	i = 0;
	while (*(format + i))
	{
		if (ft_strchr(*(format + i), '%'))
		{
			conversion_count++;
		}
		i++;
	}
	while (conversion_count)
		va_arg(ap_copy, int);
	if ()
		return (FALSE);
	return (TRUE);
}
