#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*cpydest;
	const char	*cpysrc;
	char		*lasts;
	char		*lastd;

	cpydest = (char*)dst;
	cpysrc = (const char*)src;
	if (dst < src)
		while (n--)
			*cpydest++ = *cpysrc++;
	else
	{
		lasts = (char*)cpysrc + (n - 1);
		lastd = cpydest + (n - 1);
		while (n--)
			*lastd-- = *lasts--;
	}
	return (dst);
}
