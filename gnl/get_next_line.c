/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:06:34 by monajjar          #+#    #+#             */
/*   Updated: 2025/02/12 13:43:09 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_file(int fd, char **pob)
{
	char	*str;
	int		i;
	char	*temp;

	str = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!str)
		return (0);
	i = read(fd, str, BUFFER_SIZE);
	if (i == -1)
	{
		free(str);
		return (-1);
	}
	str[i] = '\0';
	temp = ft_strjoin(*pob, str);
	free(*pob);
	*pob = temp;
	free(str);
	return (i);
}

static char	*extract_line(char **pob)
{
	char	*line;
	char	*temp;

	line = copyl(*pob);
	temp = new_line(*pob);
	*pob = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*pob;
	ssize_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 0x7fffffff)
		return (NULL);
	while (!(ft_strchr(pob, '\n')))
	{
		i = read_file(fd, &pob);
		if (i == 0)
			break ;
		if (i == -1)
		{
			free(pob);
			pob = NULL;
			return (NULL);
		}
	}
	return (extract_line(&pob));
}
