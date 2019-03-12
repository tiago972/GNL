#include "../includes/libft.h"

char	*ft_strcat(char *dest, char *src)
{
	char	*cpydest;
	char	*cpysrc;

	cpydest = dest;
	cpysrc = src;
	while (*cpydest)
		cpydest++;
	while (*cpysrc)
		*cpydest++ = *cpysrc++;
	*cpydest = '\0';
	return (dest);
}
