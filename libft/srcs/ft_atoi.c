/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:38:36 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 16:14:04 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(char *str)
{
	int			sign;
	char		*cpy;
	long int	res;

	sign = 1;
	res = 0;
	cpy = str;
	while (*cpy && (*cpy == ' ' || *cpy == '\f' || *cpy == '\n' || *cpy == '\r'
				|| *cpy == '\t' || *cpy == '\v'))
		cpy++;
	if (*cpy == '+' || *cpy == '-')
	{
		sign = (*cpy == '-') ? -1 : 1;
		cpy++;
	}
	while (*cpy && *cpy >= '0' && *cpy <= '9')
	{
		res = res * 10 + *cpy - '0';
		if (res < 0 && str[0] == '-')
			return (0);
		else if (res < 0)
			return (-1);
		cpy++;
	}
	return (res * sign);
}
