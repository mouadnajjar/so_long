/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:20:49 by monajjar          #+#    #+#             */
/*   Updated: 2025/02/21 14:49:41 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
}

char	**init_and_fill(t_map *game)
{
	char	**dup_map;

	find_player(game);
	dup_map = duplicated_map(game, game->height);
	if (!dup_map)
	{
		freed(game);
		exit (1);
	}
	flood_fill(dup_map, game->player_x, game->player_y);
	return (dup_map);
}

int	check_path(t_map *game)
{
	char	**dup_map;
	int		y;
	int		x;

	dup_map = init_and_fill(game);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C' || game->map[y][x] == 'E')
			{
				if (dup_map[y][x] != 'V')
				{
					free_map(dup_map, game->height);
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	free_map(dup_map, game->height);
	return (1);
}

static void	free_win(t_map *game)
{
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
}

void	check_win_size(t_map *game)
{
	int	screen_width;
	int	screen_height;
	int	window_width;
	int	window_height;

	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	window_width = game->width * 32;
	window_height = game->height * 32;
	if (window_width > screen_width || window_height > screen_height)
	{
		ft_putstr_fd("\033[1;31mError\nScreen too big!\n\033[1;0m", 2);
		free_win(game);
		exit (1);
	}
}
