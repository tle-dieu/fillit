/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:21:41 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/27 19:02:19 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	t_map		*map;
	t_tetri		*tetri;

	if (ac != 2 && write(1, "usage: ./fillit source_file\n", 28))
		return (1);
	if (!(tetri = ft_reader(av[1])))
	{
		write(1, "error\n", 6);
		return (1);
	}
	if (!(map = create_min_map(tetri)))
		return (1);
	while (!(solve_map(tetri, map)))
	{
		free_map(map);
		if (!(map->content = create_map(map->size += 1)))
		{
			free(map);
			return (1);
		}
	}
	print_map(map);
	free_tetri(tetri);
	return (0);
}
