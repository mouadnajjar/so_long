/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_needed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:18:39 by monajjar          #+#    #+#             */
/*   Updated: 2025/02/17 19:16:11 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_error(void)
{
	ft_putstr_fd("\033[1;31mError\033[1;0m\n", 2);
	exit (EXIT_FAILURE);
}

static int	count_set(char s1, char const *set)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (s1 == set[j])
		{
			return (1);
		}
		j++;
	}
	return (0);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s;

	s = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (s);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	size_t	start;
	char	*string;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && count_set(s1[start], set))
	{
		start++;
	}
	while (end > start && count_set(s1[end], set))
	{
		end--;
	}
	i = end - start + 1;
	string = (char *)malloc(i + 1);
	if (!string)
		return (NULL);
	ft_strlcpy(string, s1 + start, i + 1);
	return (string);
}
