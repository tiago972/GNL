#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*res;
	char	*cpy;

	if (!(res = (char*)malloc(sizeof(char) * size)))
			return (NULL);
	cpy = res;
	while ((size_t)(cpy - res) < size)
		*cpy++ = 0;
	return ((void*)res);
}
