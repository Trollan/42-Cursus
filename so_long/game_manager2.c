/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:49:15 by mansanch          #+#    #+#             */
/*   Updated: 2023/05/17 19:27:29 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_data(t_game_data *game, char **map)
{
	int	i;

	game->width = ft_strlen(map[0]);
	i = -1;
	while (map[++i])
		;
	game->heigth = i;
}

int	ft_count_collectables(t_game_data *game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == COLLECTABLE)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_set_floor_z(t_game_data *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			mlx_set_instance_depth(&game->img.floor_img->instances[k], 0);
			k++;
			j++;
		}
		i++;
	}
}

void	ft_set_exit_z(t_game_data *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] == EXIT)
		{
			mlx_set_instance_depth(&game->img.exitdoor_img->instances[k], 0);
			k++;
			j++;
		}
		i++;
	}
}

int	ft_game_main(t_game_data *game)
{
	t_game_assets_textures	textures;

	game->collectable_count = 0;
	game->move_count = 0;
	game->seta_count = 0;
	ft_map_data(game, game->map);
	game->mlx = mlx_init(game->width * 64,
			game->heigth * 64, "mansanch", false);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->collectable_max = ft_count_collectables(game);
	if (ft_draw_map(game, &textures) == FALSE)
	{
		return (0);
	}
	ft_set_exit_z(game);
	ft_set_floor_z(game);
	mlx_loop_hook(game->mlx, ft_gamemanager, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
