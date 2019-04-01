/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:51:58 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 13:51:59 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*cpys;
	char		d;

	d = (const char)c;
	cpys = s;
	while (*cpys)
		cpys++;
	if (*cpys == d)
		return ((char*)cpys);
	cpys--;
	while (cpys - s >= 0)
	{
		if (*cpys == d)
			return ((char*)cpys);
		cpys--;
	}
	return (NULL);
}
