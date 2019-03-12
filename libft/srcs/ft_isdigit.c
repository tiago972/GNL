#include "../includes/libft.h"

int		ft_isdigit(int	s)
{
	if (!(s >= '0' && s <= '9'))
		return (0);
	return (1);
}
