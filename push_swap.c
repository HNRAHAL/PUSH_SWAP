#include "push_swap.h"

// deal with the INT MAX MIN problem

int main(int ac, char **av)
{
    t_stacks *stack_a;
    t_stacks *stack_b;
    t_stacks *tmp;

    stack_a = NULL;
    stack_b = NULL;
    if(ac == 1)
        print_error();

    check_input_data(ac, av);
    arg_count_check(ac ,av, &stack_a);
    check_duplicates(&stack_a);
    if(is_sorted(stack_a) == 0)
        sort_numbers(&stack_a, &stack_b);
    tmp = stack_a;
    while(tmp)
    {
        printf("%d ", tmp->num);
        tmp = tmp->next;
    }
    // printf("NULL");
    printf("\n");
    if(is_sorted(stack_a) == 1)
        printf("OK\n");
    else if(is_sorted(stack_a) == 0)
        printf("KO\n");
    free_nodes(&stack_a);
    free_nodes(&stack_b);
    
    return(0);
}