#include "../includes/libft.h"

size_t	ft_strlen(char *str)
{
	char	*cpy;

	cpy = str;
	while (*cpy)
		cpy++;
	return (cpy - str);
}
