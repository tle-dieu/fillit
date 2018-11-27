/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:46:50 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/27 18:42:52 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int			connection_check(char *tetri)
{
	int i;
	int	connect;

	i = 0;
	connect = 0;
	while (i < 20)
	{
		if (tetri[i] == '#')
		{
			if (i + 1 < 20 && tetri[i + 1] == '#')
				connect++;
			if (i - 1 >= 0 && tetri[i - 1] == '#')
				connect++;
			if (i + 5 < 20 && tetri[i + 5] == '#')
				connect++;
			if (i - 5 >= 0 && tetri[i - 5] == '#')
				connect++;
		}
		i++;
	}
	if (connect <= 4)
		return (1);
	return (0);
}

int			buff_check(char *tetri)
{
	int blocks;
	int	i;

	blocks = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (tetri[i] != '.' && tetri[i] != '#')
				return (1);
			if (tetri[i] == '#')
				blocks++;
		}
		else if (tetri[i] != '\n')
			return (1);
		i++;
	}
	if (blocks != 4 || connection_check(tetri))
		return (1);
	return (0);
}

t_tetri		*get_tetri(t_tetri **first_tetri, t_tetri *tetri, char *str)
{
	t_tetri *new;

	if (!(new = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	new->content = moove_tetri(ft_strsplit(str, '\n'));
	new->next = NULL;
	if (tetri)
	{
		new->id = tetri->id + 1;
		tetri->next = new;
	}
	else
	{
		*first_tetri = new;
		new->id = 'A';
	}
	if (new->id > 'Z')
		return (NULL);
	return (new);
}

t_tetri		*ft_reader(char *file)
{
	char		buff[22];
	int			ret;
	t_tetri		*tetri;
	t_tetri		*first_tetri;
	int			fd;

	first_tetri = NULL;
	tetri = NULL;
	if (((fd = open(file, O_RDONLY)) < 0))
		return (NULL);
	while ((ret = read(fd, buff, 21)) >= 20)
	{
		buff[ret] = '\0';
		if (buff_check(buff) || !(tetri = get_tetri(&first_tetri, tetri, buff)))
			break ;
	}
	close(fd);
	if (!first_tetri || ret || *(ft_strrchr(buff, '\n') - 1) == '\n')
	{
		free_tetri(first_tetri);
		return (NULL);
	}
	return (first_tetri);
}
