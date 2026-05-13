/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:53:11 by hrahal            #+#    #+#             */
/*   Updated: 2026/05/13 19:53:11 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_word_count(char *str, char c)
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

int	return_word_len(char *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] == c && str[i])
		i++;
	if (str[i] != c)
	{
		while (str[i] != c && str[i])
		{
			len++;
			i++;
		}
	}
	return (len);
}

char	**ft_split(char *str, char c)
{
	char	**new_str;
	int		word_count;
	int		word_len;
	int		i;
	int		j;
	int		k;

	word_count = return_word_count(str, c);
	new_str = malloc(sizeof(char *) * (word_count + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		k = 0;
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c)
		{
			
			word_len = return_word_len(str, c, i);
			new_str[j] = malloc(sizeof(char *) * word_len + 1);
			if (new_str[j] == NULL)
			{
				free_v2(new_str);
				return (NULL);
			}
			while (str[i] != c && str[i])
				new_str[j][k++] = str[i++];
			new_str[j][k] = '\0';
			j++;
		}
	}
	new_str[j] = NULL;
	return (new_str);
}
