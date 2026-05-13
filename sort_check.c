/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:54:11 by hrahal            #+#    #+#             */
/*   Updated: 2026/05/13 19:54:11 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stacks *stack_a)
{
	t_stacks	*head;
	t_stacks	*tmp;
	int			num;

	head = stack_a;
	tmp = stack_a->next;
	while (tmp)
	{
		num = head->num;
		if (num > tmp->num)
			return (0);
		head = head->next;
		tmp = tmp->next;
	}
	return (1);
}
