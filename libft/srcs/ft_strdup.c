#include "../includes/libft.h"

char	*ft_strdup(char *str)
{
	char	*cpy;
	char	*res;

	if (!(cpy = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	res = cpy;
	while (*str)
		*cpy++ = *str++;
	*cpy = '\0';
	return (res);
}
