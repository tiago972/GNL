#include "../includes/libft.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	char			*cpy;
	unsigned char	d;
	
	cpy = (char*)b;
	d = (unsigned char)c;
	while (len--)
		*cpy++ = d;
	return (b);
}
