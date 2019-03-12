#include "../includes/libft.h"

void	ft_strclr(char *s)
{
	char	*cpy;
	
	if (!s)
		return ;
	cpy = s;
	while (*cpy)
		*cpy++ = '\0';
}
