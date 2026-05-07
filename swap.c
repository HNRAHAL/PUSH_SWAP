# include "push_swap.h"

void sa_op(t_stacks **stack_a)
{
    t_stacks *tmp;
    t_stacks *head;
    t_stacks *last_node;

    head = *stack_a;
    last_node = *stack_a;
    tmp = head;

    while(last_node->next)
        last_node = last_node->next;
    last_node->next = NULL;

    tmp = tmp->next->next;
    *stack_a = (*stack_a)->next;
    (*stack_a)->next = head;
    head->next = tmp;
    write(1, "sa\n", 3);
}

void sb_op(t_stacks **stack_b)
{
    t_stacks *tmp;
    t_stacks *head;
    t_stacks *last_node;

    head = *stack_b;
    last_node = *stack_b;
    tmp = head;

    while(last_node->next)
        last_node = last_node->next;
    last_node->next = NULL;

    tmp = tmp->next->next;
    *stack_b = (*stack_b)->next;
    (*stack_b)->next = head;
    head->next = tmp;
    write(1, "sb\n", 3);
}
