/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:03:38 by yena              #+#    #+#             */
/*   Updated: 2023/01/23 13:32:08 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *backup)
{
	size_t	line_length;
	char	*line;

	if (!backup || !*backup)
		return (NULL);
	line_length = ft_strlen(backup) - ft_strlen(ft_strchr(backup, '\n'));
	if (ft_strchr(backup, '\n'))
		line_length++;
	line = (char *)malloc(sizeof(char) * (line_length + 1));
	if (!line)
		return (NULL);
	line = (char *)ft_memcpy(line, backup, line_length);
	*(line + line_length) = 0;
	return (line);
}

char	*update_backup(char *old_backup, char *buffer)
{
	char	*new_backup;

	if (!old_backup)
		new_backup = ft_strdup(buffer);
	else if (!*buffer)
		new_backup = ft_strdup(old_backup);
	else
		new_backup = ft_strjoin(old_backup, buffer);
	return (new_backup);
}

char	*fill_backup(int fd, char *backup, char *buffer)
{
	int		read_bytes;
	char	*update_result;

	while (!ft_strchr(buffer, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		else if (!read_bytes)
			break ;
		*(buffer + read_bytes) = 0;
		update_result = update_backup(backup, buffer);
		if (!update_result)
			break ;
		free(backup);
		backup = update_result;
	}
	free(buffer);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	char		*temp_backup;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	*buffer = 0;
	temp_backup = fill_backup(fd, backup, buffer);
	line = extract_line(temp_backup);
	if (line)
		backup = ft_strdup(temp_backup + ft_strlen(line));
	free(temp_backup);
	return (line);
}
