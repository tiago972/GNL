/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:41:30 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 14:14:14 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long int	nb2;

	nb2 = nb;
	if (nb < 0)
	{
		nb2 = -nb2;
		ft_putchar_fd('-', fd);
	}
	if (nb2 >= 10)
		ft_putnbr_fd((nb2 / 10), fd);
	ft_putchar_fd((nb2 % 10) + '0', fd);
}
