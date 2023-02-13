/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:36:28 by yena              #+#    #+#             */
/*   Updated: 2022/12/19 15:28:16 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# define S_HEXA_SET "0123456789abcdef"
# define L_HEXA_SET "0123456789ABCDEF"

/*********************************  ******************************/
int	ft_printf(const char *format, ...);

int	convert_to_char(int c);
int	convert_to_string(char *formatted);
int	convert_to_address(unsigned long decimal_addr);
int	convert_to_number(long long src);
int	convert_to_hexa(unsigned int decimal, char conversion);

int	decimal_to_radix(unsigned long decimal, const char *radix_str,
		int radix);
#endif
