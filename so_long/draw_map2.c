/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:53:46 by mansanch          #+#    #+#             */
/*   Updated: 2023/05/17 20:01:59 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_add_texture2(t_game_assets_textures *textureAssets)
{
	textureAssets->icon_tx = mlx_load_png("./textures/icon.png");
	if (textureAssets->icon_tx == NULL)
	{
		mlx_delete_texture(textureAssets->floor_tx);
		mlx_delete_texture(textureAssets->wall_tx);
		mlx_delete_texture(textureAssets->exit_tx);
		return (FALSE);
	}
	textureAssets->icon2_tx = mlx_load_png("./textures/icon2.png");
	if (textureAssets->icon2_tx == NULL)
	{
		mlx_delete_texture(textureAssets->floor_tx);
		mlx_delete_texture(textureAssets->wall_tx);
		mlx_delete_texture(textureAssets->exit_tx);
		mlx_delete_texture(textureAssets->icon_tx);
		return (FALSE);
	}
	return (TRUE);
}

int	ft_add_texture3(t_game_assets_textures *textureAssets)
{
	textureAssets->collectable_tx = mlx_load_png("./textures/collectable.png");
	if (textureAssets->collectable_tx == NULL)
	{
		mlx_delete_texture(textureAssets->floor_tx);
		mlx_delete_texture(textureAssets->wall_tx);
		mlx_delete_texture(textureAssets->exit_tx);
		mlx_delete_texture(textureAssets->icon_tx);
		mlx_delete_texture(textureAssets->icon2_tx);
		return (FALSE);
	}
	return (TRUE);
}
