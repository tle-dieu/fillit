/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:51:03 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/21 20:14:40 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

int		ft_reader(int fd)
{
	char	buff[551];
	int		ret;
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 1;
	ft_bzero(buff, 551);
	if ((ret = read(fd, buff, 550)) && ret != -1)
	{
	if (ret > 545 || ret < 16)
		return (-1);
	while (i < 550)
	{
		if (!(i + j % 5))
		{
			if (buff[i] != '\n')
				return (-1);
			if (buff[i] == buff[i - 1])
				j--;
		}
		i++;
	}
	i = 0;
	while (buff[i] && i < 550)
	{
		if (buff[i] != '\n' && buff[i] != '.' && buff[i] != '#')
			return (-1);
/*		if ((i % 4 == 0))
			if (buff[i] != '\n')
				return (-1);
*/		i++;
	}
	tab = ft_strsplit(buff, '\n');
	ft_print_words_tables(tab);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int fd;

	if (ac != 2)
		return (-1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (-1);
	printf("read: %d\n", ft_reader(fd));
	return (0);
}
