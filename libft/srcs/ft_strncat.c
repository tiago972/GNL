/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:51:39 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 13:51:40 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *dest, char *src, size_t n)
{
	char	*cpydest;
	char	*cpysrc;

	cpydest = dest;
	cpysrc = src;
	while (*cpydest)
		cpydest++;
	while (n-- && *cpysrc)
		*cpydest++ = *cpysrc++;
	*cpydest = '\0';
	return (dest);
}
