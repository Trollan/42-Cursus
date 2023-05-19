/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:23:35 by mansanch          #+#    #+#             */
/*   Updated: 2023/05/12 14:23:35 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"

# define MOVE 64
# define DELAY 500
//typedef
typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}t_bool;

typedef struct s_game_assets_2d
{
	mlx_image_t	*enemy_img;
	mlx_image_t	*enemy2_img;
	mlx_image_t	*collectable_img;
	mlx_image_t	*collectable2_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*exitdoor_img;
	mlx_image_t	*exitdoor2_img;
	mlx_image_t	*floor_img;
	mlx_image_t	*icon_img;
	mlx_image_t	*icon2_img;
}t_game_assets_img;

typedef struct s_player
{
	int	x;
	int	y;
}t_player;

typedef enum e_tiles
{
	VOID = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	EXIT = 'E',
	INIT = 'P',
}t_tiles;

typedef struct s_game_data
{
	int						init;
	int						collectable;
	int						exit;
	int						floor;
	char					**map;
	int						heigth;
	int						width;
	int						collectable_count;
	int						collectable_max;
	int						seta_count;
	int						move_count;
	char					**dup_map;
	mlx_t					*mlx;
	struct s_player			player;
	struct s_game_assets_2d	img;
}t_game_data;

typedef struct s_game_assets_textures
{
	mlx_texture_t	*enemy_tx;
	mlx_texture_t	*enemy2_tx;
	mlx_texture_t	*collectable_tx;
	mlx_texture_t	*collectable2_tx;
	mlx_texture_t	*wall_tx;
	mlx_texture_t	*exit_tx;
	mlx_texture_t	*exit2_tx;
	mlx_texture_t	*floor_tx;
	mlx_texture_t	*icon_tx;
	mlx_texture_t	*icon2_tx;
}t_game_assets_textures;

char	**ft_read_map(char	*file);
int		ft_check_rectangle(char **map);
int		ft_check_wall(char	**map);
int		ft_check_tile(char	**map);
int		ft_check_exit(t_game_data	*game);
int		ft_check_map(char	**map, t_game_data	*game);
int		ft_add_texture(t_game_assets_textures *textureAssets);
void	ft_texture_to_img(t_game_assets_textures *textureAssets,
			t_game_assets_img *imageAssets, mlx_t *mlx);
void	ft_add_images(t_game_data *game, t_game_assets_img *imgAssets,
			int x, int y);
void	ft_add_tiles(t_game_data *game, t_game_assets_img *imgAssets);
int		ft_draw_map(t_game_data *game, t_game_assets_textures *textureAssets);
int		ft_add_texture2(t_game_assets_textures *textureAssets);
int		ft_add_texture3(t_game_assets_textures *textureAssets);
void	ft_remove_collectable(t_game_data *game);
void	ft_collected(t_game_data *game);
void	ft_gamemanager(void *param);
int		ft_path(t_game_data *game, char *file);
int		ft_check_path(t_game_data *game);
int		*ft_start(char **map);
void	ft_flood_fill(t_game_data *game, int x, int y);
void	ft_move_left(t_game_data *game);
void	ft_move_right(t_game_data *game);
void	ft_move_up(t_game_data *game);
void	ft_move_down(t_game_data *game);
int		ft_game_main(t_game_data *game);
void	ft_set_exit_z(t_game_data *game);
void	ft_set_floor_z(t_game_data *game);
int		ft_count_collectables(t_game_data *game);
void	ft_map_data(t_game_data *game, char **map);
int		ft_argv(char *argv);
void	ft_free_map(char **map);
int		main(int argc, char **argv);

#endif
