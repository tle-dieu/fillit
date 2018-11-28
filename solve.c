/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:34:53 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/28 17:45:50 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	place_tetri(t_tetri *tetri, t_map *map, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetri->content[j][i] == '#')
				map->content[x + j][y + i] = tetri->id;
			i++;
		}
		j++;
	}
}

static int	possible_to_place(t_tetri *tetri, t_map *map, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetri->content[j][i] == '#')
			{
				if (j + x >= map->size || i + y >= map->size
						|| map->content[x + j][i + y] != '.')
					return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

static void	remove_tetri(char id, t_map *map)
{
	int blocks;
	int x;
	int y;

	blocks = 0;
	x = 0;
	while (x < map->size)
	{
		y = 0;
		while (y < map->size)
		{
			if (map->content[x][y] == id)
			{
				map->content[x][y] = '.';
				blocks++;
			}
			y++;
		}
		if (blocks == 4)
			break ;
		x++;
	}
}

int			solve_map(t_tetri *actual_tetri, t_map *map)
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
