/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:53:50 by hrahal            #+#    #+#             */
/*   Updated: 2026/05/13 19:53:50 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot_op(t_stacks **stack, char stack_type, int double_move_check)
{
	t_stacks	*tmp;
	t_stacks	*head;
	t_stacks	*second_last;

	head = *stack;
	tmp = head;
	while (tmp->next->next)
		tmp = tmp->next;
	second_last = tmp;
	tmp = tmp->next;
	second_last->next = NULL;
	*stack = tmp;
	(*stack)->next = head;
	if (double_move_check == 0 && stack_type == 'a')
		write(1, "rra\n", 4);
	else if (double_move_check == 0 && stack_type == 'b')
		write(1, "rrb\n", 4);
	else
		return ;
}

void	rrr_op(t_stacks **stack_a, t_stacks **stack_b)
{
	rev_rot_op(stack_a, 'a', 1);
	rev_rot_op(stack_b, 'b', 1);
	write(1, "rrr\n", 4);
}
