/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:54:54 by hrahal            #+#    #+#             */
/*   Updated: 2026/05/13 19:54:57 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	overflow_check_v2(long num, t_stacks **stack_a, char **str)
{
	int	result = 0;

	if ((num > INT_MAX) || (num < INT_MIN))
		result = -1;
	if (result == -1)
		free_and_exit(stack_a, str, 2);
	else
		return ;
}

int	convert_num_v2(int sign, char c, long *num)
{
	int	digit = c - '0';

	if (sign == 1 && (*num > (LONG_MAX - digit) / 10))
		return (-1);
	if (sign == -1 && (-(*num) < (LONG_MIN + digit) / 10))
		return (-1);
	*num = *num * 10 + digit;
	return (0);
}

int	sign_check(char **str, int i, int *j)
{
	int	sign = 1;

	if (str[i] && (str[i][*j] == '-' || str[i][*j] == '+'))
	{
		if (str[i][*j] == '-')
			sign = -1;
		(*j)++;
	}
	return (sign);
}

long	ft_atol_v2(t_stacks **stack_a, char **str)
{
	static int	i = 0;
	int			result1;
	long		num;
	int			sign;
	int			j;

	num = 0;
	j = 0;
	while (str[i] && ((str[i][j] == ' ') || (str[i][j] >= 9 && str[i][j] <= 13)))
		j++;
	sign = sign_check(str, i, &j);
	while (str[i] && is_num(str[i][j]))
	{
		result1 = convert_num_v2(sign, str[i][j], &num);
		if (result1 == -1)
			free_and_exit(stack_a, str, 2);
		j++;
	}
	num *= sign;
	overflow_check_v2(num, stack_a, str);
	i++;
	return (num);
}
