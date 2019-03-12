#include "../includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	void	*cpy;
	void	*res;
	int		n;

	cpy = ft_memchr(src, c, len);
	if (cpy)
	{
		n =  cpy - src + 1;
		res  = ft_memcpy(dest, src, cpy - src + 1);
		return (res + n);
	}
	ft_memcpy(dest, src, len);
	return (NULL);
}
