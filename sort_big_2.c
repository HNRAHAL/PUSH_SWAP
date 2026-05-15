/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:54:06 by hrahal            #+#    #+#             */
/*   Updated: 2026/05/13 19:54:06 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_condition_one(t_stacks * *stack_a, t_stacks * *stack_b,
	t_stacks	*cheap_node, int condition_num)
{
	if (condition_num == 1)
	{
		while ((node_pos(*stack_a, cheap_node->target_node) != 0)
				&& (node_pos(*stack_b, cheap_node->num) != 0))
		rr_op(stack_a, stack_b);
	}
	else if (condition_num == 2)
	{
		while ((node_pos(*stack_a, cheap_node->target_node) != 0)
				&& (node_pos(*stack_b, cheap_node->num) != 0))
		rrr_op(stack_a, stack_b);
	}
}

void push_condition_two(t_stacks * *stack_b, t_stacks * cheap_node,
	int	condition_num)
{
	if (condition_num == 1)
	{
		while (node_pos(*stack_b, cheap_node->num) != 0)
			rot_op(stack_b, 'b', 0);
	}
	else if (condition_num == 2)
	{
		while (node_pos(*stack_b, cheap_node->num) != 0)
			rev_rot_op(stack_b, 'b', 0);
	}
}

void push_condition_three(t_stacks * *stack_a, t_stacks * cheap_node,
	int	condition_num)
{
	if (condition_num == 1)
	{
		while (node_pos(*stack_a, cheap_node->target_node) != 0)
			rot_op(stack_a, 'a', 0);
	}
	else if (condition_num == 2)
	{
		while (node_pos(*stack_a, cheap_node->target_node) != 0)
			rev_rot_op(stack_a, 'a', 0);
	}
}

void	push_to_a(t_stacks **stack_a, t_stacks **stack_b, t_stacks *cheap_node)
{
	int	median_a;
	int	median_b;
	int	index_a;
	int	index_b;

	median_a = stack_size(*stack_a) / 2;
	median_b = stack_size(*stack_b) / 2;
	index_a = cheap_node->target_index;
	index_b = cheap_node->main_index;
	if (index_a > 0 && index_b > 0 && index_a <= median_a
			&& index_b <= median_b)
	push_condition_one(stack_a, stack_b, cheap_node, 1);
	else if (index_a > 0 && index_b > 0 && index_a > median_a
			&& index_b > median_b)
	push_condition_one(stack_a, stack_b, cheap_node, 2);
	if (cheap_node->main_index <= median_b)
		push_condition_two(stack_b, cheap_node, 1);
	else
		push_condition_two(stack_b, cheap_node, 2);
	if (cheap_node->target_index <= median_a)
		push_condition_three(stack_a, cheap_node, 1);
	else
		push_condition_three(stack_a, cheap_node, 2);
	pa_op(stack_a, stack_b);
}

void	final_sort(t_stacks **stack_a)
{
	int	min;
	int	min_index;
	int	median;

	min = return_min_value(*stack_a);
	min_index = node_pos(*stack_a, min);
	median = stack_size(*stack_a) / 2;
	if (min_index <= median)
	{
		while (min_index-- > 0)
			rot_op(stack_a, 'a', 0);
	}
	else
	{
		while (min_index++ < stack_size(*stack_a))
			rev_rot_op(stack_a, 'a', 0);
	}
}
