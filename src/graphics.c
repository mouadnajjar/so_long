/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:33:03 by monajjar          #+#    #+#             */
/*   Updated: 2025/02/16 17:19:22 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_map *game)
{
	int	height;
	int	width;

	init_sprites(game);
	game->sprites.player = mlx_xpm_file_to_image(game->mlx,
			"../assets/player.xpm", &width, &height);
	game->sprites.coins = mlx_xpm_file_to_image(game->mlx,
			"../assets/coin.xpm", &width, &height);
	game->sprites.floor = mlx_xpm_file_to_image(game->mlx,
			"../assets/floor.xpm", &width, &height);
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx,
			"../assets/door.xpm", &width, &height);
	game->sprites.wall = mlx_xpm_file_to_image(game->mlx,
			"../assets/wall.xpm", &width, &height);
	game->sprites.open_door = mlx_xpm_file_to_image(game->mlx,
			"../assets/open_door.xpm", &width, &height);
	game->sprites.player_on_door = mlx_xpm_file_to_image(game->mlx,
			"../assets/player_on_door.xpm", &width, &height);
	check_sprites(game);
}

static void	put_sprite_to_window(t_map *game, char px, int x, int y)
{
	void	*img;

	img = NULL;
	if (px == '1')
		img = game->sprites.wall;
	else if (px == '0')
		img = game->sprites.floor;
	else if (px == 'C')
		img = game->sprites.coins;
	else if (px == 'E' && game->collectibles != 0)
		img = game->sprites.exit;
	if (game->collectibles == 0 && px == 'E')
		img = game->sprites.open_door;
	if (x == game->player_x && y == game->player_y)
	{
		if (game->on_exit)
			img = game->sprites.player_on_door;
		else
			img = game->sprites.player;
	}
	if (img)
		mlx_put_image_to_window(game->mlx,
			game->window, img, x * 32, y * 32);
}

void	render_map(t_map *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			put_sprite_to_window(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
