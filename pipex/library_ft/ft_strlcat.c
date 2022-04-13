#include "../inc/pipex.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_length;
	size_t	src_length;

	i = 0;
	j = ft_strlen(dest);
	src_length = ft_strlen(src);
	dst_length = ft_strlen(dest);
	if (size == 0)
		return (src_length);
	if (size <= dst_length)
		return (size + src_length);
	while (src[i] && dst_length + i < size - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	if (dst_length > size)
		return (src_length + size);
	else
		return (src_length + dst_length);
}
