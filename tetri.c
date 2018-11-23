/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:53:12 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/23 17:31:23 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	find_x_y(char **tetri, int *x_min, int *y_min)
{
	int y;
	int x;

	x = 0;
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

	x_min = 3;
	y_min = 3;
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
