#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned const char	*n_s1;
	unsigned const char	*n_s2;

	n_s1 = (unsigned const char *)s1;
	n_s2 = (unsigned const char *)s2;
	i = 0;
	while (i < n)
	{
		if ((n_s1[i] != n_s2[i]) || (n_s1[i] == '\0'))
			return (n_s1[i] - n_s2[i]);
		i++;
	}
	return (0);
}


int char_search(const char *s, char c)
{
    int i;

    i = 0;
    while(s[i])
    {
        if(s[i] == c)
            return(1);
        i++;
    }
    return(0);
}

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return(i);
}