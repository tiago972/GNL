#include "../includes/libft.h"

void	ft_putnbr(int nb)
{
	long int    nb2;

	nb2 = nb;
	if ( nb < 0) 
	{
		nb2 = -nb2;
		ft_putchar('-');
	}
	if (nb2 >= 10)
		ft_putnbr(nb2 / 10);
	ft_putchar((nb2 % 10) + '0');
}
