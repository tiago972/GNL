#include "../includes/libft.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;
	
	if (!ptr)
		return (ft_memalloc(new_size));
	if (!(new_ptr = ft_memalloc(new_size)))
		return (NULL);
	free(ptr);
	return (new_ptr);
}
