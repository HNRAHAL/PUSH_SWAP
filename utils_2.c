/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:54:46 by hrahal            #+#    #+#             */
/*   Updated: 2026/05/13 19:54:46 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_pos(t_stacks *stack, int num)
{
	t_stacks	*tmp;
	int			i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (num == tmp->num)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

int	return_max_value(t_stacks *stack)
{
	t_stacks	*tmp;
	int			num;

	tmp = stack;
	num = tmp->num;
	while (tmp)
	{
		if (tmp->num > num)
			num = tmp->num;
		tmp = tmp->next;
	}
	return (num);
}

int	return_min_value(t_stacks *stack)
{
	t_stacks	*tmp;
	int			num;

	tmp = stack;
	num = tmp->num;
	while (tmp)
	{
		if (tmp->num < num)
			num = tmp->num;
		tmp = tmp->next;
	}
	return (num);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
