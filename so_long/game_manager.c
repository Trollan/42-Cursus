/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:27:23 by mansanch          #+#    #+#             */
/*   Updated: 2023/05/17 17:09:20 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_remove_collectable(t_game_data *game)
{
	int	i;

	i = 0;
	while (i < game->collectable_max)
	{
		if ((((*game).img.collectable_img->instances[i].y
					== (*game).img.icon_img->instances[0].y)
				&& ((*game).img.collectable_img->instances[i].x
					== (*game).img.icon_img->instances[0].x))
			&& (*game).img.collectable_img->instances[i].enabled == true)
		{
			(*game).img.collectable_img->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

void	ft_collected(t_game_data *game)
{
	int32_t	x;
	int32_t	y;

	y = game->img.icon_img->instances[0].x / 64;
	x = game->img.icon_img->instances[0].y / 64;
	if (game->map[x][y] == COLLECTABLE)
	{
		ft_remove_collectable(game);
		game->map[x][y] = VOID;
		game->collectable_count++;
	}
	else if (game->map[x][y] == EXIT && game->collectable_count
		== game->collectable_max)
	{
		mlx_close_window(game->mlx);
	}
}

void	ft_gamemanager(void *param)
{
	t_game_data	*game;
	mlx_t		**mlx;

	game = (t_game_data *)param;
	mlx = &game->mlx;
	if (mlx_is_key_down(*mlx, MLX_KEY_ESCAPE))
		mlx_close_window(*mlx);
	else if (mlx_is_key_down(*mlx, MLX_KEY_W)
		|| mlx_is_key_down(*mlx, MLX_KEY_UP))
		ft_move_up(game);
	else if (mlx_is_key_down(*mlx, MLX_KEY_A)
		|| mlx_is_key_down(*mlx, MLX_KEY_LEFT))
		ft_move_left(game);
	else if (mlx_is_key_down(*mlx, MLX_KEY_S)
		|| mlx_is_key_down(*mlx, MLX_KEY_DOWN))
		ft_move_down(game);
	else if (mlx_is_key_down(*mlx, MLX_KEY_D)
		|| mlx_is_key_down(*mlx, MLX_KEY_RIGHT))
		ft_move_right(game);
	ft_collected(game);
}
