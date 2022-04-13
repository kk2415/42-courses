#include "philosophers.h"

int	is_alloc_error(void *addr)
{
	if (addr == NULL)
		return (TRUE);
	return (NORMAL);
}
