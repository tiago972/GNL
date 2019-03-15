#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*cpys;
	char		d;

	d = (const char)c;
	cpys = s;
	while (*cpys)
	{
		if (*cpys == d)
			return ((char*)cpys);
		cpys++;
	}
	if (*cpys == c)
		return ((char*)cpys);
	return (NULL);
}
