/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:51:42 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 14:16:31 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	char			*cpys1;
	char			*cpys2;
	unsigned char	c1;
	unsigned char	c2;

	cpys1 = s1;
	cpys2 = s2;
	while (n-- && (*cpys1 || *cpys2))
	{
		c1 = *cpys1;
		c2 = *cpys2;
		if (c1 != c2)
			return (c1 - c2);
		cpys1++;
		cpys2++;
	}
	return (0);
}
