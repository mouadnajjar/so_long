/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:31:27 by monajjar          #+#    #+#             */
/*   Updated: 2025/02/15 15:40:46 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_sprites(t_map *game)
{
	if (!game->sprites.floor || !game->sprites.exit
		|| !game->sprites.wall || !game->sprites.player
		|| !game->sprites.coins || !game->sprites.open_door
		|| !game->sprites.player_on_door)
	{
		ft_printf("\033[1;31mError: load_textures failed\033[0m\n");
		close_window(game);
	}
}

void	init_sprites(t_map *game)
{
	game->sprites.player = NULL;
	game->sprites.coins = NULL;
	game->sprites.floor = NULL;
	game->sprites.exit = NULL;
	game->sprites.wall = NULL;
	game->sprites.open_door = NULL;
	game->sprites.player_on_door = NULL;
}

void	frees_sprites(t_map *game)
{
	if (game->sprites.player != NULL)
		destroy_image(game, game->sprites.player);
	if (game->sprites.coins != NULL)
		destroy_image(game, game->sprites.coins);
	if (game->sprites.floor != NULL)
		destroy_image(game, game->sprites.floor);
	if (game->sprites.exit != NULL)
		destroy_image(game, game->sprites.exit);
	if (game->sprites.wall != NULL)
		destroy_image(game, game->sprites.wall);
	if (game->sprites.open_door != NULL)
		destroy_image(game, game->sprites.open_door);
	if (game->sprites.player_on_door != NULL)
		destroy_image(game, game->sprites.player_on_door);
}
