/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:52:49 by hrahal            #+#    #+#             */
/*   Updated: 2026/05/13 19:52:49 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input_data(int ac, char **av)
{
	if (ac == 2)
		check_single_arg_version(av);
	else if (ac > 2)
		check_normal_version(ac, av);
}

void	check_single_arg_version(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i] == '\0')
			print_error();
		while (av[1][i])
		{
			while (av[1][i] == ' ')
				i++;
			if (av[1][i] == '-' && is_num(av[1][i + 1]))
				i++;
			else if (is_num(av[1][i]))
				i++;
			else
				print_error();
		}
	}
}

void	check_normal_version(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			print_error();
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && av[i][j] == '-' && is_num(av[i][j + 1]))
				j++;
			else if (is_num(av[i][j]))
				j++;
			else
				print_error();
		}
		i++;
	}
}
