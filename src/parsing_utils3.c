/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:57:19 by monajjar          #+#    #+#             */
/*   Updated: 2025/02/19 15:29:38 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_character(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'E');
}

void	is_valid_map(t_map *game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= game->height - 1)
	{
		x = 0;
		while (x <= game->width - 1)
		{
			if (!is_valid_character(game->map[y][x]))
			{
				ft_putstr_fd("\033[1;31mError\n\033[1;0m", 2);
				freed(game);
				exit (1);
			}
			x++;
		}
		y++;
	}
}
