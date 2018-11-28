/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:57:12 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/28 17:41:59 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_tetri
{
	char			id;
	char			**content;
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_map
{
	char			**content;
	int				size;
}					t_map;

t_tetri				*ft_reader(char *file);
void				free_tetri(t_tetri *tetri);
char				**moove_tetri(char **tetri);
t_map				*create_min_map(t_tetri *tetri);
char				**create_map(int size);
int					solve_map(t_tetri *actual_tetri, t_map *map);
void				print_map(t_map *map);
void				free_map(t_map *old_map);

#endif
