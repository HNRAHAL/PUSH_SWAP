# include "push_swap.h"

void rot_op(t_stacks **stack, char stack_type, int double_move_check)
{
    t_stacks *head;
    t_stacks *tmp;

    tmp = *stack;
    *stack = (*stack)->next;
    head = *stack;
    while(head->next)
        head = head->next;
    head->next = tmp;
    tmp->next = NULL;
    if(double_move_check == 0 && stack_type == 'a')
        write(1, "ra\n", 3);
    else if(double_move_check == 0 && stack_type == 'b')
        write(1, "rb\n", 3);
    else 
        return;
}

void rr_op(t_stacks **stack_a, t_stacks **stack_b)
{
    rot_op(stack_a,'a',1);
    rot_op(stack_b,'b', 1);
    write(1, "rr\n", 3);
}
