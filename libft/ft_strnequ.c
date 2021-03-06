/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:56:41 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/08 17:48:38 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!n)
		return (1);
	if (s1 && s2)
	{
		while (*s1 == *s2)
		{
			if (!--n || (!*s1 && !*s2))
				return (1);
			s1++;
			s2++;
		}
	}
	return (0);
}
