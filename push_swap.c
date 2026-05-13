/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:53:30 by hrahal            #+#    #+#             */
/*   Updated: 2026/05/13 19:53:30 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stack_a;
	t_stacks	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		exit(0);
	check_input_data(ac, av);
	arg_count_check(ac, av, &stack_a);
	check_duplicates(&stack_a);
	if (is_sorted(stack_a) == 0)
		sort_numbers(&stack_a, &stack_b);
	free_nodes(&stack_a);
	free_nodes(&stack_b);
	return (0);
}
