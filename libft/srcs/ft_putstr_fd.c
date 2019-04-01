/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:41:51 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/01 13:41:53 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_fd(const char *str, int fd)
{
	char *cpy;

	if (!str)
		return ;
	cpy = (char*)str;
	while (*cpy)
	{
		ft_putchar_fd(*cpy, fd);
		cpy++;
	}
}
