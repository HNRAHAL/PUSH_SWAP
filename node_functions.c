#include "push_swap.h"

t_stacks *create_node(int content)
{
    t_stacks *new_node;
    new_node = malloc(sizeof(t_stacks));
    if(!new_node)
        return NULL;
    new_node->next = NULL;
    new_node->num = content;
    return (new_node);
}

void add_back_a(t_stacks **stack_a, t_stacks *new_num)
{
    t_stacks *head;
    head = *stack_a;
    if(*stack_a == NULL)
    {
        *stack_a = new_num;
        return;
    }
    while(head->next)
        head = head->next;
    head->next = new_num;
}

void add_front_a(t_stacks **stack_a, t_stacks *new_node)
{
    t_stacks *tmp;
    tmp = *stack_a;

    *stack_a = new_node;
    new_node->next = tmp;
}

void add_front_b(t_stacks **stack_b, t_stacks *new_node)
{
    t_stacks *tmp;
    tmp = *stack_b;

    *stack_b = new_node;
    new_node->next = tmp;
}

int stack_size(t_stacks *stack)
{
    int count;

    count = 0;
    while(stack)
    {   
        count++;
        stack = stack->next;
    }
    return count;
}