/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:53:05 by hrahal            #+#    #+#             */
/*   Updated: 2026/05/13 19:53:05 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_v2(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_nodes(t_stacks **stack)
{
	t_stacks	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	free_and_exit(t_stacks **stack_a, char **str, int version)
{
	if (version == 1)
	{
		free_nodes(stack_a);
		print_error();
	}
	if (version == 2)
	{
		free_v2(str);
		free_nodes(stack_a);
		print_error();
	}
}
