/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:40:50 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/27 16:47:15 by tle-dieu         ###   ########.fr       */
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

void	free_tetri(t_tetri *tetri)
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
