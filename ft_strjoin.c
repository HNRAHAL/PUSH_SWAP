#include "pipex.h"

static char	*ft_strcpy(char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

static char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	while (s2[i])
	{
		s1[i + len] = s2[i];
		i++;
	}
	s1[i + len] = '\0';
	return (s1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*str_join;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str_join = malloc(sizeof(char) * (total_len + 1));
	if (!str_join)
		return (NULL);
	ft_strcpy(str_join, s1);
	ft_strcat(str_join, s2);
	return (str_join);
}