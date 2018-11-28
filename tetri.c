/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:53:12 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/28 17:44:54 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	find_x_y(char **tetri, int *x_min, int *y_min)
{
	int y;
	int x;

	x = 0;
	*x_min = 3;
	*y_min = 3;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
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

char		**moove_tetri(char **tetri)
{
	int x_min;
	int y_min;
	int x;
	int y;

	x = 0;
	find_x_y(tetri, &x_min, &y_min);
	while (x < 4)
	{
		y = 0;
		while (y < 4)
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

void		free_tetri(t_tetri *tetri)
{
	int		i;
	t_tetri	*next;

	while (tetri)
	{
		i = 0;
		while (i < 4)
			free(tetri->content[i++]);
		free(tetri->content);
		next = tetri->next;
		free(tetri);
		tetri = next;
	}
}
