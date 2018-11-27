/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:20:21 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/27 18:43:34 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	free_map(t_map *old_map)
{
	int i;

	i = 0;
	while (i < old_map->size)
		free(old_map->content[i++]);
	free(old_map->content);
}

void	print_map(t_map *map)
{
	int j;

	j = 0;
	while (j < map->size)
		ft_putendl(map->content[j++]);
	free_map(map);
	free(map);
}

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

t_map	*create_min_map(t_tetri *tetri)
{
	t_map	*map;
	int		size;

	size = 1;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
	{
		free_tetri(tetri);
		return (NULL);
	}
	while ((tetri = tetri->next))
		size++;
	size *= 4;
	while (!(ft_sqrt(size)))
		size++;
	size = ft_sqrt(size);
	map->size = size;
	if (!(map->content = create_map(size)))
	{
		free_tetri(tetri);
		free(map);
		return (NULL);
	}
	return (map);
}
