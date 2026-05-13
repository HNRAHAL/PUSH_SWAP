/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:52:40 by hrahal            #+#    #+#             */
/*   Updated: 2026/05/13 19:52:40 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_stacks **stack_a) // check header tokyo
{
	t_stacks	*head;
	t_stacks	*tmp;
	int			num;

	head = *stack_a;
	tmp = head;
	while (head)
	{
		num = head->num;
		tmp = head->next;
		while (tmp)
		{
			if (num == tmp->num)
			{
				free_nodes(stack_a);
				print_error();
			}
			tmp = tmp->next;
		}
		head = head->next;
	}
}
