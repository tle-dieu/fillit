/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:46:50 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/23 17:43:20 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*int		connection_check(char *tetri)
  {
  int i;

  i = 0;
  while (i < 20)
  {
  if (tetri[i] == '#')
  {
  if (!((i + 1 < 20 && tetri[i + 1] == '#')
  || (i - 1 >= 0 && tetri[i - 1] == '#')
  || (i + 5 < 20 && tetri[i + 5] == '#')
  || (i - 5 >= 0 && tetri[i - 5] == '#')))
  return (1);
  }
  i++;
  }
  return (0);
  }*/

/*-----------------OR----------------*/

int			connection_check(char *tetri)
{
	int i;
	int	connect;

	i = 0;
	while (i < 20)
	{
		if (tetri[i] == '#')
		{
			connect = 0;
			if (i + 1 < 20 && tetri[i + 1] == '#')
				connect++;
			else if (i - 1 >= 0 && tetri[i - 1] == '#')
				connect++;
			else if (i + 5 < 20 && tetri[i + 5] == '#')
				connect++;
			else if (i - 5 >= 0 && tetri[i - 5] == '#')
				connect++;
			if (!(connect))
				return (1);
		}
		i++;
	}
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

t_fillit	*get_tetri(t_fillit **begin_list, t_fillit *list, char *tetri)
{
	t_fillit *new;

	if (!(new = (t_fillit *)malloc(sizeof(t_fillit))))
		return (NULL);
	new->tetri = moove_tetri(ft_strsplit(tetri, '\n'));
	new->next = NULL;
	new->x = 0;
	new->y = 0;
	if (list)
	{
		new->id = list->id + 1;
		list->next = new;
	}
	else
	{
		*begin_list = new;
		new->id = 'A';
	}
	if (new->id > 'Z')
		return (NULL);
	return (new);
}

void		ft_print_list(t_fillit *list)
{
	int	i;

	while (list)
	{
		printf("id: %c\n", list->id);
		i = 0;
		while (list->tetri[i])
			printf("%s\n", list->tetri[i++]);
		printf("\n");
		list = list->next;
	}
}

t_fillit	*ft_reader(int fd)
{
	char		buff[22];
	int			ret;
	t_fillit	*list;
	t_fillit	*begin_list;

	begin_list = NULL;
	list = NULL;
	while ((ret = read(fd, buff, 21)) >= 20)
	{
		buff[ret] = '\0';
		if (buff_check(buff) || !(list = get_tetri(&begin_list, list, buff)))
			return (NULL);
	}
	if (!begin_list || ret || *(ft_strrchr(buff, '\n') - 1) == '\n')
		return (NULL);
	ft_print_list(begin_list);
	return (begin_list);
}
