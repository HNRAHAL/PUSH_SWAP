#include "push_swap.h"

int bigger_num_check(t_stacks *stack, int num)
{
    t_stacks *tmp;
    tmp = stack;

    while(tmp)
    {
        if(tmp->num > num)
            return(1);
        tmp = tmp->next;
    }
    return(0);
}

int find_closest_bigger(t_stacks *stack, int num)
{
    t_stacks *tmp;
    tmp = stack;
    int found = 0;

    long closest_big = LONG_MAX;

    while(tmp)
    {
        found = bigger_num_check(stack, num);
        if(found == 1)
        {
            if(tmp->num > num && closest_big > tmp->num)
                closest_big = tmp->num;
        }
        else if(found == 0)
            closest_big = return_min_value(stack);
        tmp = tmp->next;
    }
    return (closest_big);
}

int find_cost(t_stacks *stack, int index)
{
    int median;
    int cost;

    median = stack_size(stack) / 2;
    if(index <= median)
        cost = index;
    else if(index > median)
        cost = stack_size(stack) - index;
    return(cost);
}

void fill_node_details(t_stacks **stack_a, t_stacks **stack_b)
{
    t_stacks *tmp;
    tmp = *stack_b; // main stack to push
    while(tmp)
    {
        tmp->target_node = find_closest_bigger(*stack_a, tmp->num);
        tmp->target_index = node_pos(*stack_a, tmp->target_node);
        tmp->main_index = node_pos(*stack_b, tmp->num);
        tmp->cost_a = find_cost(*stack_a, tmp->target_index);
        tmp->cost_b = find_cost(*stack_b, tmp->main_index);
        tmp->total_cost = tmp->cost_a + tmp->cost_b;
        tmp = tmp->next;
    }
}

t_stacks *find_cheapest_node(t_stacks *stack)
{
    t_stacks *tmp;
    t_stacks *cheap_node;
    tmp = stack;
    long cheapest = LONG_MAX;
    while(tmp)
    {
        if(tmp->total_cost < cheapest)
        {
            cheapest = tmp->total_cost;
            cheap_node = tmp;
        }
        tmp = tmp->next;
    }
    return(cheap_node);
}
