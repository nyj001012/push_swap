/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:00:34 by yena              #+#    #+#             */
/*   Updated: 2022/12/19 14:13:02 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	convert_to_char(int c)
{
	return (write(1, &c, 1));
}

int	convert_to_string(char *formatted)
{
	long long	length;
	int			status;

	length = 0;
	if (!formatted)
		return (write(1, "(null)", 6));
	if (!*formatted)
		return (0);
	while (*(formatted + length))
	{
		status = write(1, formatted + length, 1);
		if (status == -1)
			return (-1);
		else
			length += status;
	}
	return (length);
}
