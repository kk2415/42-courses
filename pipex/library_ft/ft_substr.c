#include "../inc/pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	n;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) > len)
		n = len;
	else
		n = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		str[i] = 0;
		return (str);
	}
	while (i < n)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
