/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhassna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 00:45:15 by zhassna           #+#    #+#             */
/*   Updated: 2025/01/07 21:51:38 by zhassna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	while (!(ft_search_nl(buffer, '\n')))
	{
		byte_readed = (int)read(fd, buffer, BUFFER_SIZE);
		if (byte_readed <= 0)
			break ;
		buffer[byte_readed] = '\0';
		reminder = ft_strjoin(reminder, buffer);
	}
	free (buffer);
	if (byte_readed < 0)
	{
		free(reminder);
		return (NULL);
	}
	return (reminder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*reminder[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reminder[fd] = ft_read_file(fd, reminder[fd]);
	if (!reminder[fd])
		return (NULL);
	line = ft_get_line(reminder[fd]);
	reminder[fd] = ft_get_next(reminder[fd]);
	return (line);
}
