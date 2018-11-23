/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:20:21 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/23 17:45:41 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

int		map_len(t_fillit *list)
{
	int		size;

	size = 1;
	while ((list = list->next))
		size++;
	size *= 4;
	while (!(ft_sqrt(size)))
		size++;
	return (ft_sqrt(size));
}

char	**create_map(int size)
{
	char	**map;
	int		i;
	int		j;

	if (!(map = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	j = 0;
	while (j < size)
	{
		i = 0;
		if (!(map[j] = ft_strnew(size)))
			return (NULL);
		while (i < size)
			map[j][i++] = '.';
		map[j++][i] = '\0';
	}
	map[j] = NULL;
	return (map);
}

char	**bigger_map(char **old_map)
{
	int i;

	i = 0;
	while (old_map[i])
		free(old_map[i++]);
	free(old_map);
	return (create_map(i + 1));
}
