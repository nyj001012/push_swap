/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:34:46 by yena              #+#    #+#             */
/*   Updated: 2022/12/19 14:50:08 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_to_format(char conversion, va_list *ap)
{
	if (conversion == 'c')
		return (convert_to_char(va_arg(*ap, int)));
	else if (conversion == 's')
		return (convert_to_string(va_arg(*ap, char *)));
	else if (conversion == 'p')
		return (convert_to_address(va_arg(*ap, unsigned long)));
	else if (conversion == 'd' || conversion == 'i')
		return (convert_to_number((long long)va_arg(*ap, int)));
	else if (conversion == 'u')
		return (convert_to_number((long long)va_arg(*ap, unsigned int)));
	else if (conversion == 'x' || conversion == 'X')
		return (convert_to_hexa(va_arg(*ap, unsigned int), conversion));
	else if (conversion == '%')
		return (write(1, "%", 1));
	else
		return (-1);
}

int	print_formatted_string(const char *format, va_list *ap)
{
	int	i;
	int	length;
	int	ret_val;

	i = 0;
	length = 0;
	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			ret_val = convert_to_format(*(format + ++i), ap);
			length += ret_val;
		}
		else
			length += write(1, (format + i), 1);
		i++;
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	int		ret_val;
	va_list	ap;
	va_list	*ap_ptr;

	va_start(ap, format);
	ap_ptr = &ap;
	ret_val = print_formatted_string(format, ap_ptr);
	va_end(ap);
	ap_ptr = NULL;
	return (ret_val);
}
