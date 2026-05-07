# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# endif

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# define STR_LIMIT 10
# define MAX 2147483647
# define MIN -2147483648


typedef struct s_stacks
{
    int                       target_node;
    int                      target_index;
    int                        main_index;
    int                        total_cost;
    int                            cost_a;
    int                            cost_b;
    int                               num;
    struct s_stacks                 *next;
}                                t_stacks;


// UTILITIES
size_t      ft_strlcpy(char *dst, const char *src, size_t dstsize);
long        ft_atol(const char *str);
int         ft_strlen(const char *str);
int         is_num(char c);
char	    **ft_split(char const *s, char c);
void        overflow_check(long num);
void        print_error(void);
int         return_min_value(t_stacks *stack);


// STACK CREATION
void        check_duplicates(t_stacks **stack_a, int ac);
void        check_input_data(int ac, char **av);

void        arg_count_check(int ac, char **av, t_stacks **stack_a);
void        create_v1_stack_a(t_stacks **stack_a, int ac ,char **av);
void        create_v2_stack_a(t_stacks **stack_a, char **av);

// NODE FUNCTIONS
t_stacks    *create_node(int content);
void        add_front_a(t_stacks **stack_a, t_stacks *new_node);
void        add_front_b(t_stacks **stack_b, t_stacks *new_node);
void        add_back_a(t_stacks **stack_a, t_stacks *new_num);
int         stack_size(t_stacks *stack);
int         node_pos(t_stacks *stack, int num);



// FREE FUNCTIONS
void        free_v2(char **str);
void        free_nodes_a(t_stacks **stack_a);
void        free_nodes_b(t_stacks **stack_b);

// STACK RELATED CHECK
int         is_sorted(t_stacks *stack_a);

// SORTING FUNCTIONS
void        sort_numbers(t_stacks **stack_a, t_stacks **stack_b);

//SORTING OPS
void        pa_op(t_stacks **stack_a, t_stacks **stack_b);
void        pb_op(t_stacks **stack_a, t_stacks **stack_b);
void        rrr_op(t_stacks **stack_a, t_stacks **stack_b);
void        rra_op(t_stacks **stack_a, int double_move_check);
void        rrb_op(t_stacks **stack_b, int double_move_check);
void        rr_op(t_stacks **stack_a, t_stacks **stack_b);
void        ra_op(t_stacks **stack_a, int double_move_check);
void        rb_op(t_stacks **stack_b, int double_move_check);
void        sa_op(t_stacks **stack_a);
void        sb_op(t_stacks **stack_b);

//SORTING FUNCTIONS
t_stacks *  find_cheapest_node(t_stacks *stack);
void        push_condition_one(t_stacks **stack_a, t_stacks **stack_b, t_stacks *cheap_node, int condition_num);
void        push_condition_two(t_stacks **stack_a, t_stacks **stack_b, t_stacks *cheap_node, int condition_num);
void        push_condition_three(t_stacks **stack_a, t_stacks **stack_b, t_stacks *cheap_node, int condition_num);
void        sort_three(t_stacks **stack_a, t_stacks **stack_b);
void        sort_three_conditions(t_stacks **stack_a, int num1, int num2, int num3);
void        fill_node_details(t_stacks **stack_a, t_stacks **stack_b);
void        push_to_a(t_stacks **stack_a, t_stacks **stack_b, t_stacks *cheap_node);
void        final_sort(t_stacks **stack_a);
int         bigger_num_check(t_stacks *stack, int num);
int         find_closest_bigger(t_stacks *stack, int num);
int         find_cost(t_stacks *stack, int index);
int         return_max_value(t_stacks *stack);




















