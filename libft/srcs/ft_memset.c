/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:40:34 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 14:12:17 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*cpy;
	unsigned char	d;

	cpy = (char*)b;
	d = (unsigned char)c;
	while (len--)
		*cpy++ = d;
	return (b);
}
