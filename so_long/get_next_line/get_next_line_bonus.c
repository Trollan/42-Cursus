/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:18:01 by mansanch          #+#    #+#             */
/*   Updated: 2023/03/09 15:53:07 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *rd_line, char *buff)
{
	size_t	x;
	size_t	i;
	char	*str;

	if (!rd_line)
	{
		rd_line = (char *)malloc(1 * sizeof(char));
		rd_line[0] = '\0';
	}
	if (!rd_line || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(rd_line) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	x = -1;
	i = 0;
	if (rd_line)
		while (rd_line[++x] != '\0')
			str[x] = rd_line[x];
	while (buff[i] != '\0')
		str[x++] = buff[i++];
	str[ft_strlen(rd_line) + ft_strlen(buff)] = '\0';
	free(rd_line);
	return (str);
}

char	*ft_read_line(int fd, char *file_rd)
{
	char	*str;
	ssize_t	rd_bytes;

	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	rd_bytes = 1;
	while (rd_bytes != 0 && !ft_strchr(file_rd, '\n'))
	{
		rd_bytes = read(fd, str, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(str);
			free(file_rd);
			return (NULL);
		}
		str[rd_bytes] = '\0';
		file_rd = ft_strjoin(file_rd, str);
	}
	free(str);
	return (file_rd);
}

char	*ft_get_line(char *file_rd)
{
	char	*line;
	int		x;

	x = 0;
	if (!file_rd[x])
		return (NULL);
	while (file_rd[x] && file_rd[x] != '\n')
		x++;
	line = (char *)malloc(sizeof(char) * x + 2);
	if (!line)
		return (NULL);
	x = 0;
	while (file_rd[x] && file_rd[x] != '\n')
	{
		line[x] = file_rd[x];
		x++;
	}
	if (file_rd[x] == '\n')
	{
		line[x] = file_rd[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}

char	*ft_save_line(char *file_rd)
{
	char	*line;
	int		x;
	int		i;

	x = 0;
	while (file_rd[x] && file_rd[x] != '\n')
		x++;
	if (!file_rd[x])
	{
		free(file_rd);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * ft_strlen(file_rd) - x + 1);
	if (!line)
		return (NULL);
	x++;
	i = 0;
	while (file_rd[x])
		line[i++] = file_rd[x++];
	line[i] = '\0';
	free(file_rd);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*file_rd[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (0);
	file_rd[fd] = ft_read_line(fd, file_rd[fd]);
	if (!file_rd[fd])
		return (NULL);
	line = ft_get_line(file_rd[fd]);
	file_rd[fd] = ft_save_line(file_rd[fd]);
	return (line);
}
