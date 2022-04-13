#include "../inc/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, ft_strlen(s1) + 1);
	ft_strlcat(ret, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	return (ret);
}
