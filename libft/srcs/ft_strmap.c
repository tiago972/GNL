/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:51:13 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 13:51:34 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char *s, char (*f)(char))
{
	char	*res;
	char	*cpys;
	char	*cpyres;

	if (!s)
		return (NULL);
	if (!(res = ft_strnew(ft_strlen(s))))
		return (NULL);
	cpys = s;
	cpyres = res;
	while (*cpys)
		*cpyres++ = f(*cpys++);
	return (res);
}
