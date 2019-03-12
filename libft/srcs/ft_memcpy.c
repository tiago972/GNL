#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*cpydest;
	const char	*cpysrc;

	cpydest = (char*)dest;
	cpysrc = (const char*)src;

	while (n--)
		*cpydest++ = *cpysrc++;
	return (dest);
}
