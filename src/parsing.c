/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:44:26 by monajjar          #+#    #+#             */
/*   Updated: 2025/02/21 14:51:12 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_elements(char *line, t_map *map_data)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			map_data->players++;
		else if (line[i] == 'C')
			map_data->collectibles++;
		else if (line[i] == 'E')
			map_data->exits++;
		i++;
	}
}

void	init_map_data(t_map *game)
{
	if (!game)
		return ;
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->moves = 0;
	game->players = 0;
	game->collectibles = 0;
	game->exits = 0;
	game->on_exit = 0;
	game->mlx = NULL;
	game->window = NULL;
}

t_map	*free_game(t_map *game)
{
	free(game);
	ft_putstr_fd("\033[1;31mError\n\033[1;0m", 2);
	exit (1);
}

int	is_valid_elements(t_map *map_data)
{
	int	i;

	if (!map_data || !map_data->map)
		return (0);
	i = 0;
	while (map_data->map[i])
	{
		count_elements(map_data->map[i], map_data);
		i++;
	}
	if (map_data->players != 1 || map_data->collectibles < 1
		|| map_data->exits != 1)
		return (0);
	return (1);
}

t_map	*laoding_map(char *filename)
{
	t_map	*game;

	game = malloc(sizeof(t_map));
	if (!game)
		exit (1);
	init_map_data(game);
	game->height = get_map_height(filename);
	if (game->height <= 0)
		free_game(game);
	game->map = read_map(filename, game->height);
	if (!game->map)
		free_game(game);
	game->width = ft_strlen(game->map[0]);
	if (!validate_shape(game->map, game->height)
		|| !validate_map_walls(game->map, game->width, game->height)
		|| !is_valid_elements(game))
	{
		freed(game);
		ft_putstr_fd("\033[1;31mError\ninvalid map\033[0m\n", 2);
		exit (1);
	}
	return (game);
}
