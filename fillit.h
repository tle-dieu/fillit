/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:57:12 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/27 16:18:47 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define ERROR (int)write(1, "error\n", 6)

# include "libft.h"

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
char				**create_map(int size);
char				**moove_tetri(char **tetri);
void				free_map(t_map *old_map);
void				remove_tetri(char id, t_map *map);
void				place_tetri(t_tetri *tetri, t_map *map, int x, int y);
int					possible_to_place(t_tetri *tetri, t_map *map, int x, int y);
int					solve_map(t_tetri *actual_tetri, t_map *map);
t_map				*create_min_map(t_tetri *tetri);
void				print_map(t_map *map);
void				free_tetri(t_tetri *tetri);

#endif
