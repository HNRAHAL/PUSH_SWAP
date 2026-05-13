/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:52:57 by hrahal            #+#    #+#             */
/*   Updated: 2026/05/13 19:52:57 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_v1_stack_a(t_stacks **stack_a, int ac, char **av)
{
	int	i;
	int	num;

	i = 1;
	*stack_a = create_node(ft_atol_v1(stack_a, av[i]));
	while (++i < ac)
	{
		num = ft_atol_v1(stack_a, av[i]);
		add_back_a(stack_a, create_node(num));
	}
}

void	create_v2_stack_a(t_stacks **stack_a, char **av)
{
	int			i;
	long		num;
	char		**str;
	t_stacks	*node;

	str = ft_split(av[1], ' ');
	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		num = ft_atol_v2(stack_a, str);
		node = create_node(num);
		add_back_a(stack_a, node);
		i++;
	}
	free_v2(str);
}

void	arg_count_check(int ac, char **av, t_stacks **stack_a)
{
	if (ac == 2)
		create_v2_stack_a(stack_a, av);
	else
		create_v1_stack_a(stack_a, ac, av);
}
