/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:52:11 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 14:19:23 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_checkchar(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int		ft_countwords(char *s, char sep)
{
	int		count;
	char	*cpy;

	count = 0;
	cpy = s;
	if (!sep)
		return (1);
	while (*cpy)
	{
		if (s == cpy && !ft_checkchar(*cpy, sep))
			count++;
		else if (!ft_checkchar(*cpy, sep) && ft_checkchar(*(cpy - 1), sep))
			count++;
		cpy++;
	}
	return (count);
}

static int		ft_countletters(char *s, char sep)
{
	int		count;
	char	*cpy;

	count = 0;
	cpy = s;
	if (!sep)
		return (1);
	while (*cpy && !ft_checkchar(*cpy, sep))
	{
		count++;
		cpy++;
	}
	return (count);
}

static char		*ft_strdup_2(char *s, char sep)
{
	char	*res;
	char	*cpy;

	if (!(res = (char*)malloc(sizeof(char) * ft_countletters(s, sep) + 1)))
		return (NULL);
	cpy = res;
	while (*s && !ft_checkchar(*s, sep))
		*cpy++ = *s++;
	*cpy = '\0';
	return (res);
}

char			**ft_strsplit(const char *s, char sep)
{
	char	*cpy;
	char	**res;
	int		j;

	if (!s)
		return (NULL);
	cpy = (char*)s;
	if (!(res = (char**)malloc(sizeof(char*) * ft_countwords(cpy, sep) + 1)))
		return (NULL);
	j = 0;
	while (*cpy)
	{
		if (cpy == s && !ft_checkchar(*cpy, sep))
			res[j++] = ft_strdup_2(cpy, sep);
		else if (!ft_checkchar(*cpy, sep) && ft_checkchar(*(cpy - 1), sep))
			res[j++] = ft_strdup_2(cpy, sep);
		cpy++;
	}
	res[j] = 0;
	return (res);
}
