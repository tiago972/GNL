/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:39:39 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 14:09:17 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	void	ft_doit(long int nbr, char *res)
{
	while (nbr >= 10)
	{
		*res++ = nbr % 10 + '0';
		nbr /= 10;
	}
	*res = nbr % 10 + '0';
}

static char		*ft_alloc(int n, int power, long int *nbr)
{
	char	*res;

	if (n < 0)
	{
		if (!(res = ft_strnew(power + 2)))
			return (NULL);
		res[power + 1] = '-';
		*nbr *= -1;
	}
	else if (!(res = ft_strnew(power + 1)))
		return (NULL);
	return (res);
}

char			*ft_itoa(int n)
{
	int			power;
	long int	nbr;
	char		*res;

	power = 0;
	nbr = n;
	if (n < 0)
		nbr = -nbr;
	while (nbr >= 10)
	{
		nbr /= 10;
		power++;
	}
	nbr = n;
	res = ft_alloc(n, power, &nbr);
	if (!res)
		return (NULL);
	ft_doit(nbr, res);
	return (ft_strrev(res));
}
