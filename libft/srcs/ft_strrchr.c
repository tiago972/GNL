#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*cpys;
	char		d;

	d = (const char)c;
	cpys = s;
	while (*cpys)
		cpys++;
	if (*cpys == c)
		return ((char*)cpys);
	cpys--;
	while (cpys - s >= 0)
	{
		if (*cpys == c)
			return ((char*)cpys);
		cpys--;
	}
	return (NULL);
}
