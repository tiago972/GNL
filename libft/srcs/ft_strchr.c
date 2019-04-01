/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:42:01 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 13:42:03 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*cpys;
	char		d;

	d = (const char)c;
	cpys = s;
	while (*cpys)
	{
		if (*cpys == d)
			return ((char*)cpys);
		cpys++;
	}
	if (*cpys == c)
		return ((char*)cpys);
	return (NULL);
}
