#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(res = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
		res[i++] = s[start++];
	return (res);
}
