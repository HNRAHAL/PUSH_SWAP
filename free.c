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

void free_nodes(t_stacks **stack)
{
    t_stacks *tmp;

    while(*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}
