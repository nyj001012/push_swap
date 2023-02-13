/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_vaildation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@studnet.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:36:01 by yena              #+#    #+#             */
/*   Updated: 2023/02/06 16:32:23 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_underflow(char *string)
{
	char	*min_int;

	min_int = "-2147483648";
	if (ft_strlen(string) > ft_strlen(min_int))
		return (true);
	else if ((ft_strlen(string) == ft_strlen(min_int)) && string[1] > '2')
		return (true);
	else if (ft_atoi(string) >= 0)
		return (true);
	return (false);
}

bool	is_overflow(char *string)
{
	char	*max_int;

	max_int = "2147483648";
	if (ft_strlen(string) > ft_strlen(max_int))
		return (true);
	else if ((ft_strlen(string) == ft_strlen(max_int)) && string[0] > '2')
		return (true);
	else if (ft_atoi(string) < 0)
		return (true);
	return (false);
}
