/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:09:41 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/20 21:06:36 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

t_fillit	*lstnew_fillit(t_fillit *list, char **tab)
{
	t_fillit 	*new;

	if (!(new = (t_fillit *)malloc(sizeof(t_fillit))))
		return (NULL);
	new->tetri = tab;
	new->next = NULL;
//	printf("ft_list avant if\n");
	if (list)
	{
//		printf("entree dans if\n");
		new->id = list->id + 1;
		list->next = new;
	}
	else
	{	
//		printf("else\n");
		new->id = 'A';
	}
//	printf("apres if\n");
	return (new);
}

void		print_list(char **tab)
{
	int i;

	i = 0;
	while (i < 5)
		printf("%s\n", tab[i++]);
}

int			main(int ac, char **av)
{
	t_fillit	*list;
	t_fillit	**begin_list;
	int			i;
	char		*tab[5];
	int			fd;

	i = 0;
	list = NULL;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
		{
			write(1, "error\n", 6);
			return (1);
		}
	//	printf("fd open\n");
		begin_list = &list; 
		while (get_next_line(fd, &tab[i]) == 1)
		{
	//		printf("boucle gnl\n");
			if (i == 3)
			{
			//	printf("creation list\n");
				if (!(list = lstnew_fillit(list, tab)))
					return (1);
				print_list(list->tetri);
//				printf("list cree\n");
			}
			if (i == 4)
			{
				if (tab[i][0])
					return (0);
				i = 0;
			}
			else
				i++;
		}
//		printf("sortie gnl boucle\n");
		close(fd);
		list = *begin_list;
		return (0);
		while (list)
		{
//			printf("boucle print_words\n");
			ft_print_words_tables(list->tetri);
			list = list->next;
		}
		return (0);
	}
	write(1, "voici l' usage\n", 15);





	return (0);
}
