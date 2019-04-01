/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:43:13 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 13:43:30 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*cpydest;
	char	*cpysrc;

	cpydest = dest;
	cpysrc = src;
	while (*cpysrc)
		*cpydest++ = *cpysrc++;
	*cpydest = '\0';
	return (dest);
}
