#include "../includes/libft.h"

char	*ft_strncat(char *dest, char *src, size_t n)
{
	char	*cpydest;
	char	*cpysrc;

	cpydest = dest;
	cpysrc = src;
	while (*cpydest)
		cpydest++;
	while (n-- && *cpysrc)
		*cpydest++ = *cpysrc++;
	*cpydest = '\0';
	return (dest);
}
