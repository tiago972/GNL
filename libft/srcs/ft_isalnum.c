#include "../includes/libft.h"

int		ft_isalnum(int s)
{
	if (ft_isalpha(s) || ft_isdigit(s))
		return (1);
	return (0);
}
