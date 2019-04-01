/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:52:25 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 14:17:38 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_checkchar(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static size_t	ft_lensize(const char *s, int *beg, int *end)
{
	char	*cpy;
	int		size;

	cpy = (char*)s;
	size = ft_strlen(cpy);
	while (*cpy && ft_checkchar(*cpy++))
		(*beg)++;
	if (*beg == size)
		return (0);
	while (*cpy)
		cpy++;
	cpy--;
	while (cpy > s && ft_checkchar(*cpy--))
		(*end)++;
	return (size - (*beg + *end));
}

char			*ft_strtrim(char const *s)
{
	char	*res;
	char	*cpyres;
	char	*cpys;
	int		beg;
	int		end;

	if (!s)
		return (NULL);
	beg = 0;
	end = 0;
	if (!(res = ft_strnew(ft_lensize(s, &beg, &end))))
		return (NULL);
	cpyres = res;
	cpys = (char*)s;
	end = ft_strlen((char*)s) - end;
	while (*(cpys + beg))
	{
		if (beg == end)
			break ;
		*cpyres++ = *(cpys + beg);
		beg++;
	}
	return (res);
}
