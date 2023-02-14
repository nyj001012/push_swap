/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:21:46 by yena              #+#    #+#             */
/*   Updated: 2023/02/14 10:22:21 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pointers(char **ptrs)
{
	int	i;

	i = 0;
	while (ptrs[i])
	{
		free(ptrs[i]);
		i++;
	}
	free(ptrs);
}