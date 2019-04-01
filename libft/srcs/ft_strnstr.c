/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:51:55 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 14:16:57 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int		i;
	int		j;
	size_t	t;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (n && *(haystack + i))
	{
		j = 0;
		t = n;
		while (*(needle + j) && *(haystack + i + j) == *(needle + j) && t)
		{
			j++;
			t--;
		}
		if (*(needle + j) == '\0')
			return ((char*)haystack + i);
		i++;
		n--;
	}
	return (NULL);
}
