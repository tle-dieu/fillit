/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:53:12 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/26 16:29:54 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	find_x_y(char **tetri, int *x_min, int *y_min)
{
	int y;
	int x;

	x = 0;
	*x_min = 3;
	*y_min = 3;
	while (tetri[x])
	{
		y = 0;
		while (tetri[x][y])
		{
			if (tetri[x][y] == '#')
			{
				*y_min = (y < *y_min ? y : *y_min);
				*x_min = (x < *x_min ? x : *x_min);
			}
			y++;
		}
		x++;
	}
}

char	**moove_tetri(char **tetri)
{
	int x_min;
	int y_min;
	int x;
	int y;

	x = 0;
	find_x_y(tetri, &x_min, &y_min);
	while (tetri[x])
	{
		y = 0;
		while (tetri[x][y])
		{
			if (tetri[x][y] == '#')
			{
				tetri[x][y] = '.';
				tetri[x - x_min][y - y_min] = '#';
			}
			y++;
		}
		x++;
	}
	return (tetri);
}

void	place_tetri(t_tetri *tetri, t_map *map, int x, int y)
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

int		possible_to_place(t_tetri *tetri, t_map *map, int x, int y)
{
	int i;
	int j;
	int size;

	j = 0;
	size = map->size;
	while (tetri->content[j])
	{
		i = 0;
		while (tetri->content[j][i])
		{
			if (tetri->content[j][i] == '#' && (j + x >= size || i + y >= size || map->content[x + j][i + y] != '.'))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	remove_tetri(char id, t_map *map)
{
	int blocks;
	int x;
	int y;

	blocks = 0;
	x = 0;
	while (map->content[x])
	{
		y = 0;
		while (map->content[x][y])
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
