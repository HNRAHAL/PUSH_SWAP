#include "push_swap.h"

void check_duplicates(t_stacks **stack_a, int ac)
{
    t_stacks *head;
    t_stacks *tmp;
    int num;

    head = *stack_a;
    while(head)
    {
        num = head->num;
        tmp = head->next;
        while(tmp)
        {
            if(num == tmp->num)
            {
                free_nodes_a(stack_a);
                print_error();
            }
            tmp = tmp->next;
        }
        head = head->next;
    }
}