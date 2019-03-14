#include "../includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *new_elem)
{
	new_elem->next = *alst;
	*alst = new_elem;
}
