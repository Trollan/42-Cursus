/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:00:16 by mansanch          #+#    #+#             */
/*   Updated: 2023/05/05 15:00:29 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*char	**ft_read_map(char *file)
{
	char	**map;
	int		fd;
	char	*line;
	char	*tmp;
	char	*map_tmp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tmp = NULL;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_tmp = tmp;
		tmp = ft_strjoin(map_tmp, line);
		free(line);
	}
	map = ft_split(tmp, '\n');
	free(tmp);
	close(fd);
	return (map);
}*/

char	**ft_read_map(char *path)
{
	int		fd;
	char	*take_map;
	char	**map;
	int		n;

	n = 0;
	take_map = ft_calloc(10000 + 1, sizeof(char));
	if (!take_map)
		return (free(take_map), NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(take_map);
		return (NULL);
	}
	n = read(fd, take_map, 10000);
	if (n == -1 || n == 0)
		return (free(take_map), NULL);
	map = ft_split(take_map, '\n');
	free(take_map);
	close(fd);
	return (map);
}
