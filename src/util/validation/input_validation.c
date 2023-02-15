/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@studnet.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:51:33 by yena              #+#    #+#             */
/*   Updated: 2023/02/14 17:30:03 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	has_empty_value(char **input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (!*input[i])
			return (true);
	}
	return (false);
}

bool	has_not_integer(char **input)
{
	int		i;
	int		j;

	i = -1;
	while (input[++i])
	{
		j = -1;
		if (input[i][0] == '-' || input[i][0] == '+')
			j++;
		while (input[i][++j])
		{
			if (!ft_isdigit(input[i][j]))
			{
				if (input[i][j] == '-' && !j)
					continue ;
				return (true);
			}
		}
	}
	return (false);
}

bool	has_overflow_or_underflow(char **input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (input[i][0] == '-' && is_underflow(input[i]))
			return (true);
		else if (input[i][0] != '-' && is_overflow(input[i]))
			return (true);
	}
	return (false);
}

bool	has_duplicates(char **input)
{
	int 	i;
	int 	j;
	char	*source;

	i = 1;
	while (input[i])
	{
		j = 0;
		source = input[i - 1];
		while (input[i + j])
		{
			if (!ft_strncmp(source, input[i + j], -1))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	is_valid_input(char **input)
{
	if (has_empty_value(input))
		return (false);
	else if (has_not_integer(input))
		return (false);
	else if (has_overflow_or_underflow(input))
		return (false);
	else if (has_duplicates(input))
		return (false);
	return (true);
}
