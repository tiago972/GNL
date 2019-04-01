/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:52:01 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 14:17:15 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrev(char *s)
{
	char	*end;
	char	*start;
	char	tmp;

	start = s;
	end = s;
	while (*end)
		end++;
	end--;
	while (end > start)
	{
		tmp = *end;
		*end-- = *start;
		*start++ = tmp;
	}
	return (s);
}
