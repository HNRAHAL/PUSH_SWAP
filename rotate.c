# include "push_swap.h"

void ra_op(t_stacks **stack_a, int double_move_check)
{
    t_stacks *head;
    t_stacks *tmp;

    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    head = *stack_a;
    while(head->next)
        head = head->next;
    head->next = tmp;
    tmp->next = NULL;
    if(double_move_check == 0)
        write(1, "ra\n", 3);
    else 
        return;
}

void rb_op(t_stacks **stack_b, int double_move_check)
{
    t_stacks *head;
    t_stacks *tmp;

    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    head = *stack_b;
    while(head->next)
        head = head->next;
    head->next = tmp;
    tmp->next = NULL;
    if(double_move_check == 0)
        write(1, "rb\n", 3);
    else    
        return;
}

void rr_op(t_stacks **stack_a, t_stacks **stack_b)
{
    ra_op(stack_a, 1);
    rb_op(stack_b, 1);
    write(1, "rr\n", 3);
}
