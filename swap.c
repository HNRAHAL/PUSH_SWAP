/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:54:36 by hrahal            #+#    #+#             */
/*   Updated: 2026/05/13 19:54:36 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_op(t_stacks **stack, char stack_type)
{
	t_stacks	*tmp;
	t_stacks	*head;
	t_stacks	*last_node;

	head = *stack;
	last_node = *stack;
	tmp = head;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = NULL;
	tmp = tmp->next->next;
	*stack = (*stack)->next;
	(*stack)->next = head;
	head->next = tmp;
	if (stack_type == 'a')
		write(1, "sa\n", 3);
	else if (stack_type == 'b')
		write(1, "sb\n", 3);
}

