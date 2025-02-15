/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:01:20 by monajjar          #+#    #+#             */
/*   Updated: 2025/02/14 13:40:47 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_map *game)
{
	frees_sprites(game);
	if (game->window != NULL)
	{
		mlx_destroy_window(game->mlx, game->window);
		game->window = NULL;
	}
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
		freed(game);
	}
	exit (0);
}

void	move_player(t_map *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (is_valid_move(game, new_x, new_y))
	{
		handle_collectibles(game, new_x, new_y);
		handle_exit(game, new_x, new_y);
		update_map(game, new_x, new_y);
		game->moves++;
		ft_printf("\033[1;32mMoves : %d\033[0m\n", game->moves);
		render_map(game);
	}
}

int	key_press(int keycode, t_map *game)
{
	if (keycode == XK_Escape)
		close_window(game);
	if (keycode == XK_w)
		move_player(game, 0, -1);
	if (keycode == XK_s)
		move_player(game, 0, 1);
	if (keycode == XK_a)
		move_player(game, -1, 0);
	if (keycode == XK_d)
		move_player(game, 1, 0);
	return (0);
}

void	setup_hook(t_map *game)
{
	mlx_hook(game->window, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->window, DestroyNotify, NoEventMask, close_window, game);
}

void	init_game(t_map *game)
{
	int		width;
	int		height;
	void	*mlx;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error: MLX init failed\n");
		exit(1);
	}
	mlx = game->mlx;
	width = game->width;
	height = game->height;
	game->window = mlx_new_window(mlx, width * 32, height * 32, "so_long");
	if (!game->window)
	{
		ft_printf("Error: Window creation failed\n");
		exit(1);
	}
}
