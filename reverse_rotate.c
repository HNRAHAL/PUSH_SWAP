# include "push_swap.h"

void rra_op(t_stacks **stack_a, int double_move_check)
{
    t_stacks *tmp;
    t_stacks *head;
    t_stacks *second_last;

    head = *stack_a;
    tmp = head;

    while(tmp->next->next)
        tmp = tmp->next;
    second_last = tmp;
    tmp = tmp->next;

    second_last->next = NULL;
    *stack_a = tmp;
    (*stack_a)->next = head;
    if(double_move_check == 0)
        write(1, "rra\n", 4);
    else    
        return;
}


void rrb_op(t_stacks **stack_b, int double_move_check)
{
    t_stacks *tmp;
    t_stacks *head;
    t_stacks *second_last;

    head = *stack_b;
    tmp = head;

    while(tmp->next->next)
        tmp = tmp->next;
    second_last = tmp;
    tmp = tmp->next;

    second_last->next = NULL;
    *stack_b = tmp;
    (*stack_b)->next = head;
    if(double_move_check == 0)
        write(1, "rrb\n", 4);
    else
        return;
}

void rrr_op(t_stacks **stack_a, t_stacks **stack_b)
{
    rra_op(stack_a, 1);
    rrb_op(stack_b, 1);
    write(1, "rrr\n", 4);
}