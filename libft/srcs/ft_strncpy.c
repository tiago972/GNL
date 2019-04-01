/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:51:44 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 13:51:47 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	char	*cpydest;
	char	*cpysrc;

	cpysrc = src;
	cpydest = dest;
	while (n-- != 0)
	{
		if ((*cpydest++ = *cpysrc++) == 0)
		{
			while (n-- != 0)
				*cpydest++ = '\0';
			break ;
		}
	}
	return (dest);
}
