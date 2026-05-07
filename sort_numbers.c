#include "push_swap.h"

void sort_numbers(t_stacks **stack_a, t_stacks **stack_b)
{
    int size = stack_size(*stack_a);
    if(size == 1)
        return;
    else if(size == 2)
        sa_op(stack_a);
    else if(size == 3)
        sort_three(stack_a, stack_b);
    else
    {
        t_stacks *cheap_node;
        while(stack_size(*stack_a) > 3)
            pb_op(stack_a, stack_b);
        sort_numbers(stack_a, stack_b);
        while(stack_size(*stack_b) > 0)
        {
            fill_node_details(stack_a, stack_b);
            cheap_node = find_cheapest_node(*stack_b);
            push_to_a(stack_a, stack_b, cheap_node);
        }
        final_sort(stack_a);
    }
}
