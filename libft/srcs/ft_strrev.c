#include "../includes/libft.h"

char	*ft_strrev(char *s)
{
	char	*end;
	char	*start;
	char	tmp;

	start = s;
	end = s;
	while(*end)
		end++;
	end--;
	while (end > start)
	{
		tmp = *end;
		*end-- = *start;
		*start++ = tmp;
	}
	return (s);
}
