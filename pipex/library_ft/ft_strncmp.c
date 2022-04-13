#include "../inc/pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;

	i = 0;
	s1_tmp = (unsigned char *)s1;
	s2_tmp = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && (s1_tmp[i] && s2_tmp[i]))
	{
		if (s1_tmp[i] != s2_tmp[i])
			return (s1_tmp[i] - s2_tmp[i]);
		i++;
	}
	if (i == n)
		i--;
	return (s1_tmp[i] - s2_tmp[i]);
}
