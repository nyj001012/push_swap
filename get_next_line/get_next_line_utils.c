/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:03:35 by yena              #+#    #+#             */
/*   Updated: 2022/10/10 15:59:24 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	if (!s)
		return (0);
	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	join_len;
	int		idx_s;
	int		idx_j;

	if (!s1 || !s2)
		return (0);
	join_len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (join_len + 1));
	if (!join)
		return (0);
	idx_s = 0;
	idx_j = 0;
	while (*(s1 + idx_s))
		*(join + idx_j++) = *(s1 + idx_s++);
	idx_s = 0;
	while (*(s2 + idx_s))
		*(join + idx_j++) = *(s2 + idx_s++);
	*(join + idx_j) = '\0';
	return (join);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	size_t	idx;
	char	*dup;

	s1_len = ft_strlen(s1);
	idx = 0;
	dup = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!dup)
		return (0);
	while (idx < s1_len)
	{
		*(dup + idx) = *(s1 + idx);
		idx++;
	}
	*(dup + idx) = '\0';
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
		else
			i++;
	}
	if (*(s + i) == (char)c)
		return ((char *)(s + i));
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (!src && !dst)
		return (0);
	while (n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		n--;
		i++;
	}
	return (dst);
}
