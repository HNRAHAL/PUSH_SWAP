/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:53:21 by hrahal            #+#    #+#             */
/*   Updated: 2026/05/13 19:53:21 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*create_node(int content)
{
	t_stacks	*new_node;

	new_node = malloc(sizeof(t_stacks));
	if (!new_node)
		return (NULL);
	new_node->num = content;
	new_node->next = NULL;
	return (new_node);
}

void	add_back_a(t_stacks **stack_a, t_stacks *new_num)
{
	t_stacks	*head;

	if ((!stack_a) || (!new_num))
		return ;
	head = *stack_a;
	if (*stack_a == NULL)
	{
		*stack_a = new_num;
		return ;
	}
	while (head->next)
		head = head->next;
	head->next = new_num;
}

void	add_front_a(t_stacks **stack_a, t_stacks *new_node)
{
	t_stacks	*tmp;

	if ((!stack_a) || (!new_node))
		return ;
	tmp = *stack_a;
	*stack_a = new_node;
	new_node->next = tmp;
}

void	add_front_b(t_stacks **stack_b, t_stacks *new_node)
{
	t_stacks	*tmp;

	if ((!stack_b) || (!new_node))
		return ;
	tmp = *stack_b;
	*stack_b = new_node;
	new_node->next = tmp;
}

int	stack_size(t_stacks *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
