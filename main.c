/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:21:41 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/23 17:48:45 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int			fd;
	char		**map;
	t_fillit	*begin_list;

	if (ac != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (1);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (ERROR);
	if (!(begin_list = ft_reader(fd)))
		return (ERROR);	
	if (!(map = create_map(map_len(begin_list))))
		return (ERROR);
	ft_putstr("map min:\n");		/* A RETIRER */
	ft_print_words_tables(map);
	ft_putchar('\n');
	if (!(map = bigger_map(map)))
		return (ERROR);
	ft_putstr("bigger map:\n");
	ft_print_words_tables(map);		/*************/
	return (0);
}
