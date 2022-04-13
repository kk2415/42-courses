#include "../inc/pipex.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(to_find);
	if (to_find[i] == 0)
		return ((char *)str);
	if (n <= 0)
		return (0);
	while (i <= (n - len) && str[i])
	{
		if (str[i] == to_find[0])
			if (ft_strncmp(&str[i], to_find, len) == 0)
				return ((char *)str + i);
		i++;
	}
	return (0);
}
