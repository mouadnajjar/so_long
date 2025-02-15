/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:13:24 by monajjar          #+#    #+#             */
/*   Updated: 2025/02/15 17:03:34 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

char	**read_map(char *filename, int height)
{
	int		fd;
	int		i;
	char	**map;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	validate_shape(char	**map, int height)
{
	size_t	width;
	int		i;

	width = ft_strlen(map[0]);
	i = 1;
	while (i <= height - 1)
	{
		if (ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

int	validate_map_walls(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width - 1)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height - 1)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_ber_file(char	*filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strcmp(filename + (len - 4), ".ber") != 0)
		return (0);
	return (1);
}
