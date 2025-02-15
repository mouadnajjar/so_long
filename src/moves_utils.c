/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:42:50 by monajjar          #+#    #+#             */
/*   Updated: 2025/02/15 17:01:42 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_move(t_map *game, int new_x, int new_y)
{
	return (new_x >= 0 && new_y >= 0 && new_x < game->width
		&& new_y < game->height && game->map[new_y][new_x] != '1');
}

void	handle_collectibles(t_map *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles--;
		game->map[new_y][new_x] = '0';
	}
}

void	handle_exit(t_map *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'E'
		&& game->collectibles == 0)
	{
		game->moves++;
		ft_printf("\033[1;32mMoves : %d\n\033[1;0m", game->moves);
		write(1, "\033[1;32mYOU WON!\033[0m\n", 19);
		close_window(game);
	}
}

void	update_map(t_map *game, int new_x, int new_y)
{
	if (game->on_exit)
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	if (game->map[new_y][new_x] == 'E')
		game->on_exit = 1;
	else
		game->on_exit = 0;
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
}

void	find_player(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
