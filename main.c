/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:21:41 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/26 16:25:25 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int			fd;
	t_map		*map;
	t_tetri		*tetri;

	if (ac != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (1);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (ERROR);
	if (!(tetri = ft_reader(fd)))
		return (ERROR);
	if (!(map = create_min_map(tetri)))
		return (ERROR);
	while (!(solve_map(tetri, map)))
	{
		map->content = bigger_map(map);
		map->size++;
	}
	ft_print_words_tables(map->content);
	return (0);
}
