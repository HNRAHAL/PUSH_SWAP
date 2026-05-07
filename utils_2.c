#include "push_swap.h"

int node_pos(t_stacks *stack, int num)
{
    t_stacks *tmp;
    int i = 0;
    tmp = stack;
    while(tmp)
    {
        if(num == tmp->num)
            return i;
        tmp = tmp->next;
        i++;
    }
    return(-1);
}

int return_max_value(t_stacks *stack)
{
    t_stacks *tmp;
    int num = 0;

    tmp = stack;
    num = tmp->num;

    while(tmp)
    {
        if(tmp->num > num)
            num = tmp->num;
        tmp = tmp->next;
    }
    return num;
}

int return_min_value(t_stacks *stack)
{
    t_stacks *tmp;
    int num = 0;

    tmp = stack;
    num = tmp->num;

    while(tmp)
    {
        if(tmp->num < num)
            num = tmp->num;
        tmp = tmp->next;
    }
    return num;
}
