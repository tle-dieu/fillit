/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:51:03 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/22 13:53:58 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

/*int		count_tetri(char *s)
  {
  int	tetri;
  int	i;

  tetri = 0;
  i = 0;
  while (s[i])
  {
  if (s[i] == '\n' && (s[i + 1] == '\n' || !s[i + 1]))
  tetri++;
  i++;
  }
  return (tetri);
  }*/

int		first_check(char *s)
{
	int    i;
	int c;

	c = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
			return (-1);
		i++;
	}
	i = 4;
	while (s[i] && i < 550)
	{
		if (s[i] != '\n')
			return (-1);
		c++;
		if (c == 4)
		{
			if ((s[++i] != '\n' || s[i + 1] == '\0') && s[i])
				return (-1);
			c = 0;
		}
		i += 5;
	}
	return (0);
}

char	**check_and_split(char *s)
{

	if (first_check(s))
		return (NULL);
	return (ft_strsplit(s, '\n'));
}

int		ft_reader(int fd)
{
	char	buff[551];
	int		ret;
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 1;
	ft_bzero(buff, 551);
	if ((ret = read(fd, buff, 550)) && ret != -1)
	{
		if (ret > 545 || ret < 16)
			return (-1);
		if (!(tab = check_and_split(buff)))
			return (-1);
		ft_print_words_tables(tab);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int fd;

	if (ac != 2)
		return (-1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (-1);
	printf("read: %d\n", ft_reader(fd));
	return (0);
}
