#include "../includes/libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*cpydest;
	char	*cpysrc;

	cpydest = dest;
	cpysrc = src;
	while (*cpysrc)
		*cpydest++ = *cpysrc++;
	*cpydest = '\0';
	return (dest);
}
