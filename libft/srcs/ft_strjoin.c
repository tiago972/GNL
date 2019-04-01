/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:50:40 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 14:16:06 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*cpys1;
	char	*cpys2;
	char	*cpyres;

	if (!s1 || !s2)
		return (NULL);
	if (!(res = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2))))
		return (NULL);
	cpys1 = (char*)s1;
	cpys2 = (char*)s2;
	cpyres = res;
	while (*cpys1)
		*cpyres++ = *cpys1++;
	while (*cpys2)
		*cpyres++ = *cpys2++;
	return (res);
}
