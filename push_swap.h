/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/13 19:53:37 by username         #+#    #+#              */
/*   Updated: 2026/05/13 20:00:27 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stacks
{
	int				target_node;
	int				target_index;
	int				main_index;
	int				total_cost;
	int				cost_a;
	int				cost_b;
	int				num;
	struct s_stacks	*next;
}	t_stacks;

// UTILITIES

// Version without split
long	ft_atol_v1(t_stacks **stack_a, const char *str);
void	convert_num_v1(int sign, char str, long *num, t_stacks **stack_a);
void	overflow_check_v1(long num, t_stacks **stack_a);
// Version with split

int		sign_check(char **str, int i, int *j);
long	ft_atol_v2(t_stacks **stack_a, char **str);
int		convert_num_v2(int sign, char str, long *num);
void	overflow_check_v2(long num, t_stacks **stack_a, char **str);
// End of atol functions
int		ft_strlen(const char *str);
int		is_num(char c);
char	**ft_split(char *s, char c);
void	print_error(void);

// STACK CREATION
void	check_duplicates(t_stacks **stack_a);
void	check_input_data(int ac, char **av);
void	check_normal_version(int ac, char **av);
void	check_single_arg_version(char **av);
void	arg_count_check(int ac, char **av, t_stacks **stack_a);
void	create_v1_stack_a(t_stacks **stack_a, int ac, char **av);
void	create_v2_stack_a(t_stacks **stack_a, char **av);

// NODE FUNCTIONS
t_stacks	*create_node(int content);
void		add_front_a(t_stacks **stack_a, t_stacks *new_node);
void		add_front_b(t_stacks **stack_b, t_stacks *new_node);
void		add_back_a(t_stacks **stack_a, t_stacks *new_num);
int			stack_size(t_stacks *stack);
int			node_pos(t_stacks *stack, int num);

// FREE FUNCTIONS
void	free_v2(char **str);
void	free_nodes(t_stacks **stack);
void	free_and_exit(t_stacks **stack_a, char **str, int version);
// STACK RELATED CHECK
int	is_sorted(t_stacks *stack_a);

// SORTING FUNCTIONS
void	sort_numbers(t_stacks **stack_a, t_stacks **stack_b);

//SORTING OPS
void	pa_op(t_stacks **stack_a, t_stacks **stack_b);
void	pb_op(t_stacks **stack_a, t_stacks **stack_b);
void	rrr_op(t_stacks **stack_a, t_stacks **stack_b);
void rev_rot_op(t_stacks * *stack, char stack_type,
	int	double_move_check);
void	rot_op(t_stacks **stack, char stack_type, int double_move_check);
void	swap_op(t_stacks **stack, char stack_type);
void	rr_op(t_stacks **stack_a, t_stacks **stack_b);

//SORTING FUNCTIONS
t_stacks	*find_cheapest_node(t_stacks *stack);
void push_condition_one(t_stacks * *stack_a, t_stacks * *stack_b,
	t_stacks	*cheap_node, int condition_num);
void push_condition_two(t_stacks * stack_b, t_stacks * cheap_node,check_normal_ver
	int	condition_num);
void push_condition_three(t_stacks * *stack_a, t_stacks * cheap_node,
	int	condition_num);
void	sort_three(t_stacks **stack_a);
void sort_three_conditions(t_stacks * *stack_a, int num1,
	int	num2, int num3);
void	fill_node_details(t_stacks **stack_a, t_stacks **stack_b);
void push_to_a(t_stacks * *stack_a, t_stacks * *stack_b,
	t_stacks	*cheap_node);
void	final_sort(t_stacks **stack_a);
int		bigger_num_check(t_stacks *stack, int num);
int		find_closest_bigger(t_stacks *stack, int num);
int		find_cost(t_stacks *stack, int index);
int		return_max_value(t_stacks *stack);
int		return_min_value(t_stacks *stack);

#endif
