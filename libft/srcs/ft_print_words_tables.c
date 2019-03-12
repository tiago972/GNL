#include "../includes/libft.h"

void	ft_print_words_tables(char **s)
{
	int		i;

	i = 0;
	if (!s)
		return;
	while (s[i])
	{
		ft_putstr(s[i++]);
		ft_putchar('\n');
	}
}
