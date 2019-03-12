#include "../includes/libft.h"

void	ft_putstr(const char *str)
{
	char *cpy;

	if (!str)
		return ;
	cpy = (char*)str;
	while (*cpy)
	{
		ft_putchar(*cpy);
		cpy++;
	}
}
