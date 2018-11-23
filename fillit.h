/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:57:12 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/23 17:44:22 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define ERROR write(1, "error\n", 6)

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_fillit
{
	char			id;
	char			**tetri;
	int				x;
	int				y;
	struct s_fillit	*next;
}					t_fillit;

t_fillit	*ft_reader(int fd);
char		**create_map(int size);
char		**moove_tetri(char **tetri);
int			map_len(t_fillit *list);
char		**bigger_map(char **old_map);

#endif
