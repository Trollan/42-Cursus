/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:43:34 by mansanch          #+#    #+#             */
/*   Updated: 2023/05/17 19:26:49 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_add_texture(t_game_assets_textures *textureAssets)
{
	textureAssets->floor_tx = mlx_load_png("./textures/floor.png");
	if (textureAssets->floor_tx == NULL)
	{
		return (FALSE);
	}
	textureAssets->wall_tx = mlx_load_png("./textures/wall.png");
	if (textureAssets->wall_tx == NULL)
	{
		mlx_delete_texture(textureAssets->floor_tx);
		return (FALSE);
	}
	textureAssets->exit_tx = mlx_load_png("./textures/exit.png");
	if (textureAssets->exit_tx == NULL)
	{
		mlx_delete_texture(textureAssets->floor_tx);
		mlx_delete_texture(textureAssets->wall_tx);
		return (FALSE);
	}
	return (TRUE);
}

void	ft_texture_to_img(t_game_assets_textures *textureAssets,
t_game_assets_img *imageAssets, mlx_t *mlx)
{
	imageAssets->floor_img = mlx_texture_to_image(mlx, textureAssets->floor_tx);
	mlx_delete_texture(textureAssets->floor_tx);
	imageAssets->wall_img = mlx_texture_to_image(mlx, textureAssets->wall_tx);
	mlx_delete_texture(textureAssets->wall_tx);
	imageAssets->exitdoor_img
		= mlx_texture_to_image(mlx, textureAssets->exit_tx);
	mlx_delete_texture(textureAssets->exit_tx);
	imageAssets->icon_img = mlx_texture_to_image(mlx, textureAssets->icon_tx);
	mlx_delete_texture(textureAssets->icon_tx);
	imageAssets->icon2_img = mlx_texture_to_image(mlx, textureAssets->icon2_tx);
	mlx_delete_texture(textureAssets->icon2_tx);
	imageAssets->collectable_img
		= mlx_texture_to_image(mlx, textureAssets->collectable_tx);
	mlx_delete_texture(textureAssets->collectable_tx);
}

void	ft_add_images(t_game_data *game, t_game_assets_img *imgAssets,
		int x, int y)
{
	mlx_image_to_window(game->mlx, imgAssets->floor_img, y * 64, x * 64);
	if (game->map[x][y] == COLLECTABLE)
	{
		mlx_image_to_window(game->mlx, imgAssets->collectable_img,
			y * 64, x * 64);
	}
	if (game->map[x][y] == WALL)
		mlx_image_to_window(game->mlx, imgAssets->wall_img, y * 64, x * 64);
	if (game->map[x][y] == EXIT)
		mlx_image_to_window(game->mlx, imgAssets->exitdoor_img, y * 64, x * 64);
}

void	ft_add_tiles(t_game_data *game, t_game_assets_img *imgAssets)
{
	int	x;
	int	y;
	int	xp;
	int	yp;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == INIT)
			{
				xp = x;
				yp = y;
			}
			ft_add_images(game, imgAssets, x, y);
			y++;
		}
		x++;
	}
	mlx_image_to_window(game->mlx, imgAssets->icon_img, yp * 64, xp * 64);
	mlx_image_to_window(game->mlx, imgAssets->icon2_img, yp * 64, xp * 64);
	imgAssets->icon2_img->instances[0].enabled = false;
}

int	ft_draw_map(t_game_data *game, t_game_assets_textures *textureAssets)
{
	if (ft_add_texture(textureAssets) == FALSE
		|| ft_add_texture2(textureAssets) == FALSE
		|| ft_add_texture3(textureAssets) == FALSE)
	{
		printf("ERROR!! Couldnt read texture!! \n");
		return (FALSE);
	}
	ft_texture_to_img(textureAssets, &(*game).img, game->mlx);
	ft_add_tiles(game, &(*game).img);
	return (TRUE);
}
