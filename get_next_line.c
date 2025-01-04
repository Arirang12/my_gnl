/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhassna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 01:33:31 by zhassna           #+#    #+#             */
/*   Updated: 2025/01/01 10:02:21 by zhassna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *buf)
{
	int		i;
	char	*line;

	i = 0;
	if (buf[i] == '\0')
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_next(char *buf)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
	{
		free (buf);
		return (NULL);
	}
	next = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	if (buf[i] == '\n')
		i++;
	while (buf[i])
		next[j++] = buf[i++];
	free (buf);
	return (next);
}

char	*ft_read_file(int fd, char *reminder)
{
	char	*buffer;
	int		byte_readed;

	byte_readed = 1;
	if (!reminder)
		reminder = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (byte_readed > 0)
	{
		byte_readed = (int)read(fd, buffer, BUFFER_SIZE);
		if (byte_readed == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[byte_readed] = '\0';
		reminder = ft_strjoin(reminder, buffer);
		if (ft_search_nl(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (reminder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*reminder;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	reminder = ft_read_file(fd, reminder);
	if (!reminder)
		return (NULL);
	line = ft_get_line(reminder);
	reminder = ft_get_next(reminder);
	return (line);
}
