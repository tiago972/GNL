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
