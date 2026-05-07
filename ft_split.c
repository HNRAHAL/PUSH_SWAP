#include "push_swap.h"

static char	**free_array(char **array, int i);
static int	word_count(const char *s, char c);
static int	word_len(const char *s, char c);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (*src && i < dstsize - 1)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}

static char	**free_array(char **array, int i)
{
	while (i-- > 0)
		free(array[i]);
	free(array);
	return (NULL);
}

static int	word_count(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			while (*s && *s != c)
				s++;
			count++;
		}
		else
		{
			while (*s == c)
				s++;
		}
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

static char	**word_store(char **array, const char *s, char c)
{
	int	len;
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			len = word_len(s, c);
			array[i] = malloc(sizeof(char) * (len + 1));
			if (!array[i])
				return (free_array(array, i));
			ft_strlcpy(array[i], s, len + 1);
			s += len;
			i++;
		}
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		wc;

	if (!s)
		return (NULL);
	wc = word_count(s, c);
	array = malloc(sizeof(char *) * (wc + 1));
	if (!array)
		return (NULL);
	return (word_store(array, s, c));
}