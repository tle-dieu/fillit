/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:27:49 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/20 15:54:15 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100

int					get_next_line(const int fd, char **line);

typedef struct		s_gnl
{
	char			*str;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

#endif
