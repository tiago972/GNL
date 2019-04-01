/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:40:15 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 13:40:18 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*cpy;
	unsigned char			d;

	d = (unsigned char)c;
	cpy = (const unsigned char*)s;
	while (n--)
	{
		if (*cpy == d)
			return ((void*)cpy);
		cpy++;
	}
	return (NULL);
}
