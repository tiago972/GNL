#include "../includes/libft.h"

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	char	*cpydest;
	char	*cpysrc;

	cpysrc = src;
	cpydest = dest;
	while (n-- != 0)
	{
		if ((*cpydest++ = *cpysrc++) == 0)
		{
			while (n-- != 0)
				*cpydest++ = '\0';
			break ;
		}
	}
	return (dest);
}
