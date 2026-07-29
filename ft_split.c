#include "pipex.h"

static void	string_check(char **new_str, int j)
{
	if (new_str[j] == NULL)
	{
		while(new_str[j])
			free(new_str[j--]);
		free(new_str);
	}
}

static int	return_word_count(char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while ((str[i] == c) && str[i])
			i++;
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (count);
}

static int	return_word_len(char *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] == c && str[i])
		(i)++;
	if (str[i] != c)
	{
		while (str[i] != c && str[i])
		{
			len++;
			(i)++;
		}
	}
	return (len);
}

static char	*store_and_copy(char *str, int *i, char c)
{
	int		j;
	int		word_len;
	char	*str_to_send;

	word_len = return_word_len(str, c, *i);
	str_to_send = malloc(sizeof(char) * (word_len + 1));
	if (str_to_send == NULL)
		return (NULL);
	j = 0;
	while (str[*i] != c && str[*i])
		str_to_send[j++] = str[(*i)++];
	str_to_send[j] = '\0';
	return (str_to_send);
}

char	**ft_split(char *str, char c)
{
	char	**new_str;
	int		word_count;
	int		i;
	int		j;

	word_count = return_word_count(str, c);
	new_str = malloc(sizeof(char *) * (word_count + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c)
		{
			new_str[j] = store_and_copy(str, &i, c);
			if (new_str[j] == NULL)
				return(string_check(new_str, j), NULL);
			j++;
		}
	}
	new_str[j] = NULL;
	return (new_str);
}