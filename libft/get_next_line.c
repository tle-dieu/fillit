/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:37:36 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/20 16:16:36 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static t_gnl	*choose_fd(t_gnl **begin_list, int fd)
{
	t_gnl *list;
	t_gnl *new;

	list = *begin_list;
	while (list)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	if (!(new = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	if (!(new->str = ft_strnew(1)))
	{
		free(new);
		return (NULL);
	}
	new->fd = fd;
	new->next = *begin_list;
	*begin_list = new;
	return (new);
}

static int		check_line(t_gnl *actual, int ret, char **line)
{
	char *tmp;

	if (ret == 0 && !ft_strlen(actual->str))
		return (0);
	if (!(*line = ft_strcdup(actual->str, '\n')))
		return (-1);
	if (ft_strclen(actual->str, '\n') < ft_strlen(actual->str))
	{
		tmp = ft_strdup((ft_strchr(actual->str, '\n') + 1));
		free(actual->str);
		actual->str = tmp;
	}
	else
		ft_strclr(actual->str);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static t_gnl	*list;
	t_gnl			*actual;
	char			*tmp;

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!(actual = choose_fd(&list, fd)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = actual->str;
		if (!(actual->str = ft_strjoin(actual->str, buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (check_line(actual, ret, line));
}
