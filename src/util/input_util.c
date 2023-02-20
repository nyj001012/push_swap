/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:46:33 by yena              #+#    #+#             */
/*   Updated: 2023/02/20 11:41:44 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Split argv(ex: "1 2 3 4 5" 12 4 to "1", "2", "3", "4", "5" "12" "4")

size_t	get_input_list_size(char **argv)
{
	size_t	size;
	int		i;
	int		j;
	char	**split_argv;

	size = 0;
	i = -1;
	while (argv[++i])
	{
		split_argv = ft_split(argv[i], ' ');
		j = -1;
		while (split_argv[++j])
			size++;
		free_pointers(split_argv);
	}
	return (size);
}

char	**make_input_lists(char **argv)
{
	char	**input_lists;
	char	**split_argv;
	int		list_index;
	int		i;

	input_lists = (char **)malloc(sizeof(char *)
			* (get_input_list_size(argv) + 1));
	list_index = -1;
	while (*argv)
	{
		split_argv = ft_split(*argv, ' ');
		i = -1;
		while (split_argv[++i])
			input_lists[++list_index] = ft_strdup(split_argv[i]);
		free_pointers(split_argv);
		argv++;
	}
	input_lists[++list_index] = NULL;
	return (input_lists);
}
