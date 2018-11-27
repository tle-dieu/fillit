/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:20:21 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/27 14:55:52 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

char	**create_map(int size)
{
	char	**new_map;
	int		i;
	int		j;

	if (!(new_map = (char **)malloc(sizeof(char *) * size)))
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
		j++;
	}
	return (new_map);
}

void	print_map(t_map *map)
{
	int j;

	j = 0;
	while (j < map->size)
		ft_putendl(map->content[j++]);
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

int		solve_map(t_tetri *actual_tetri, t_map *map)
{
	int x;
	int y;

	if (!actual_tetri)
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
