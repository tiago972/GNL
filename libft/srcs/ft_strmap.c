#include "../includes/libft.h"

char	*ft_strmap(char *s, char (*f)(char))
{
	char	*res;
	char	*cpys;
	char	*cpyres;

	if (!s)
		return (NULL);
	if (!(res = ft_strnew(ft_strlen(s))))
		return (NULL);
	cpys = s;
	cpyres = res;
	while (*cpys)
		*cpyres++ = f(*cpys++);
	return (res);
}
