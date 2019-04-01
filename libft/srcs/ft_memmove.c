/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:40:31 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 13:40:33 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*cpydest;
	const char	*cpysrc;
	char		*lasts;
	char		*lastd;

	cpydest = (char*)dst;
	cpysrc = (const char*)src;
	if (dst < src)
		while (n--)
			*cpydest++ = *cpysrc++;
	else
	{
		lasts = (char*)cpysrc + (n - 1);
		lastd = cpydest + (n - 1);
		while (n--)
			*lastd-- = *lasts--;
	}
	return (dst);
}
