/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:40:08 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 14:09:54 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*res;
	char	*cpy;

	if (!(res = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	cpy = res;
	while ((size_t)(cpy - res) < size)
		*cpy++ = 0;
	return ((void*)res);
}
