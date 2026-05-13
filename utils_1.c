/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:54:41 by hrahal            #+#    #+#             */
/*   Updated: 2026/05/13 19:54:41 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	overflow_check_v1(long num, t_stacks **stack_a)
{
	if ((num > INT_MAX) || (num < INT_MIN))
		free_and_exit(stack_a, NULL, 1);
}

void	convert_num_v1(int sign, char str, long *num, t_stacks **stack_a)
{
	int	digit;

	digit = str - '0';
	if (sign == 1 && (*num > (LONG_MAX - digit) / 10))
		free_and_exit(stack_a, NULL, 1);
	if (sign == -1 && (-(*num) < (LONG_MIN + digit) / 10))
		free_and_exit(stack_a, NULL, 1);
	*num = *num * 10 + digit;
}

long	ft_atol_v1(t_stacks **stack_a, const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (is_num(str[i]))
	{
		convert_num_v1(sign, str[i], &num, stack_a);
		i++;
	}
	num *= sign;
	overflow_check_v1(num, stack_a);
	return (num);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
