/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:20:45 by monajjar          #+#    #+#             */
/*   Updated: 2025/02/14 14:45:02 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_error(t_map *game)
{
	if (!check_path(game))
	{
		freed(game);
		ft_printf("\033[1;31mERROR ! : your map has an invalid path!\033[0m\n");
		exit (1);
	}
}

int	main(int ac, char **av)
{
	t_map		*game;

	if (ac != 2)
	{
		ft_printf("\033[1;31mUsage : ./so_long <filname.ber>\033[0m\n");
		return (1);
	}
	if (!is_ber_file(av[1]))
		ft_error();
	game = laoding_map(av[1]);
	if (!game->map)
		ft_error();
	path_error(game);
	init_game(game);
	check_win_size(game);
	load_textures(game);
	render_map(game);
	setup_hook(game);
	mlx_loop(game->mlx);
	return (0);
}
