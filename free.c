#include "push_swap.h"

void free_v2(char **str)
{
    int i;

    i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void free_nodes_a(t_stacks **stack_a)
{
    t_stacks *tmp;

    while(*stack_a)
    {
        tmp = (*stack_a)->next;
        free(*stack_a);
        *stack_a = tmp;
    }
}

void free_nodes_b(t_stacks **stack_b)
{
    t_stacks *tmp;

    while(*stack_b)
    {
        tmp = (*stack_b)->next;
        free(*stack_b);
        *stack_b = tmp;
    }
}