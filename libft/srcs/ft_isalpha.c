#include "../includes/libft.h"

int		ft_isalpha(int	s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
		return (1);
	return (0);
}
