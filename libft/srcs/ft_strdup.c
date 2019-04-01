/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:49:42 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 13:49:44 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(char *str)
{
	char	*cpy;
	char	*res;

	if (!(cpy = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	res = cpy;
	while (*str)
		*cpy++ = *str++;
	*cpy = '\0';
	return (res);
}
