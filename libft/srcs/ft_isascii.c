#include "../includes/libft.h"

int		ft_isascii(int s)
{
	if (s < 0 || s > 127)
		return (0);
	return (1);
}
