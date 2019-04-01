/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:40:24 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 14:11:07 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*cpydest;
	const char	*cpysrc;

	cpydest = (char*)dest;
	cpysrc = (const char*)src;
	while (n--)
		*cpydest++ = *cpysrc++;
	return (dest);
}
