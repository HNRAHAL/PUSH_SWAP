# include "push_swap.h"

void pa_op(t_stacks **stack_a, t_stacks **stack_b)
{
    t_stacks *tmp;
    
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    add_front_a(stack_a, tmp);
    write(1, "pa\n", 3);
}

void pb_op(t_stacks **stack_a, t_stacks **stack_b)
{
    t_stacks *tmp;
    
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    add_front_b(stack_b, tmp);
    write(1, "pb\n", 3);
}
