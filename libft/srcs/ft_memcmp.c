#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char		*cpys1;
	const char		*cpys2;
	unsigned char	c1;
	unsigned char	c2;

	cpys1 = (const char*)s1;
	cpys2 = (const char*)s2;
	while (n--)
	{
		c1 = *cpys1;
		c2 = *cpys2;
		if (c1 != c2)
			return (c1 - c2);
		cpys1++;
		cpys2++;
	}
	return (c1 - c2);
}
