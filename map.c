/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:20:21 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/26 16:29:37 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

char	**create_map(int size)
{
	char	**new_map;
	int		i;
	int		j;

	if (!(new_map = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	j = 0;
	while (j < size)
	{
		i = 0;
		if (!(new_map[j] = ft_strnew(size)))
		{
			while (j--)
				free(new_map[j]);
			free(new_map);
			return (NULL);
		}
		while (i < size)
			new_map[j][i++] = '.';
		new_map[j++][i] = '\0';
	}
	new_map[j] = NULL;
	return (new_map);
}

char	**bigger_map(t_map *old_map)
{
	int i;
	char **content;

	i = 0;
	content = old_map->content;
//	while (*content)
//		free(*content);
//	free(content);
	return (create_map(old_map->size + 1));
}

int     solve_map(t_tetri *actual_tetri, t_map *map)
{
	int x;
	int y;

	if (!(actual_tetri))
		return (1);
	x = 0;
	while (x < map->size)
	{
		y = 0;
		while (y < map->size)
		{
			if (possible_to_place(actual_tetri, map, x, y))
			{
				place_tetri(actual_tetri, map, x, y);
				if (solve_map(actual_tetri->next, map))
					return (1);
			}
			y++;
		}
		x++;
	}
	remove_tetri(actual_tetri->id - 1, map);
	return (0);
}

t_map	*create_min_map(t_tetri *tetri)
{
	t_map	*map;
	int		size;

	size = 1;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	while ((tetri = tetri->next))
		size++;
	size *= 4;
	while (!(ft_sqrt(size)))
		size++;
	size = ft_sqrt(size);
	map->size = size;
	if (!(map->content = create_map(size)))
	{
		free(map);
		return (NULL);
	}
	return (map);
}
