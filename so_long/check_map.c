/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:43:05 by mansanch          #+#    #+#             */
/*   Updated: 2023/05/17 17:43:05 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_rectangle(char	**map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != (int)len)
			return (FALSE);
		else
			i++;
	}
	return (i);
}

int	ft_check_wall(char	**map)
{
	size_t	i;
	int		j;
	int		height;

	height = 0;
	while (map[height])
		height++;
	i = 0;
	while ((int)i < ft_strlen(map[0]))
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (FALSE);
		else
			i++;
	}
	j = 1;
	while (j < (height - 1))
	{
		if (map[j][0] != '1' || map[j][ft_strlen(map[0]) - 1] != '1')
			return (FALSE);
		else
			j++;
	}
	return (TRUE);
}

int	ft_check_tile(char	**map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (!((map[x][y] == WALL || map[x][y] == VOID)
				|| (map[x][y] == EXIT || map[x][y] == INIT)
				|| (map[x][y] == COLLECTABLE)))
				return (FALSE);
			else
				y++;
		}
		x++;
	}
	return (TRUE);
}

int	ft_check_exit(t_game_data	*game)
{
	int	i;
	int	j;

	game->collectable = 0;
	game->exit = 0;
	game->init = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == EXIT)
				game->exit++;
			else if (game->map[i][j] == INIT)
				game->init++;
			else if (game->map[i][j] == COLLECTABLE)
				game->collectable++;
			j++;
		}
		i++;
	}
	if (game->collectable < 1 || game->exit != 1 || game->init != 1)
		return (FALSE);
	return (TRUE);
}

int	ft_check_map(char	**map, t_game_data	*game)
{
	if (ft_check_rectangle(map) == FALSE)
	{
		ft_printf("Error! The map is not a rectangle.\n");
		return (FALSE);
	}
	else if (ft_check_wall(map) == FALSE)
	{
		ft_printf("Error! The map is not closed..\n");
		return (FALSE);
	}
	else if (ft_check_tile(map) == FALSE)
	{
		ft_printf("Error! The map have a wrong tile.\n");
		return (FALSE);
	}
	else if (ft_check_exit(game) == FALSE)
	{
		ft_printf("Error! The map do not have an exit \n");
		ft_printf("or an init position or at least one collectable.\n");
		return (FALSE);
	}
	else
		return (TRUE);
}
