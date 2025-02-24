/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:52:56 by monajjar          #+#    #+#             */
/*   Updated: 2025/02/16 16:56:03 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

void	freed(t_map *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map, game->height);
	game->map = NULL;
	free(game);
	game = NULL;
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*new;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**duplicated_map(t_map *game, int height)
{
	int		i;
	char	**new_map;

	new_map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i <= height - 1)
	{
		new_map[i] = ft_strdup(game->map[i]);
		if (!new_map[i])
		{
			while (--i >= 0)
				free(new_map[i]);
			free(new_map);
			freed(game);
			exit (1);
		}
		i++;
	}
	new_map[height] = (NULL);
	return (new_map);
}

void	destroy_image(t_map *game, void *img)
{
	mlx_destroy_image(game->mlx, img);
	img = NULL;
}
