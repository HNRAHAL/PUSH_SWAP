/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:54:25 by hrahal            #+#    #+#             */
/*   Updated: 2026/05/13 19:54:25 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

void	sort_numbers(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*cheap_node;
	int			size;

	size = stack_size(*stack_a);
	if (size == 1)
		return ;
	else if (size == 2)
		swap_op(stack_a, 'a');
	else if (size == 3)
		sort_three(stack_a);
	else
	{
		while (stack_size(*stack_a) > 3)
			pb_op(stack_a, stack_b);
		sort_numbers(stack_a, stack_b);
		while (stack_size(*stack_b) > 0)
		{
			fill_node_details(stack_a, stack_b);
			cheap_node = find_cheapest_node(*stack_b);
			push_to_a(stack_a, stack_b, cheap_node);
		}
		final_sort(stack_a);
	}
}
