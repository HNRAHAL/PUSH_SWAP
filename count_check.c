# include "push_swap.h"

void create_v1_stack_a(t_stacks **stack_a, int ac ,char **av)
{
    int i;
    int num;
    
    i = 1;
    *stack_a = create_node(ft_atol(av[i]));
    while(++i < ac)
    {
        num = ft_atol(av[i]);
        add_back_a(stack_a, create_node(num));
    }
}

void create_v2_stack_a(t_stacks **stack_a, char **av)
{
    int i;
    int num;
    char **str;

    str = ft_split(av[1], ' ');
    i = 0;
    while(str[i])
    {
        num = ft_atol(str[i]);
        add_back_a(stack_a, create_node(num));
        i++;
    }
    free_v2(str);
}

void arg_count_check(int ac, char **av, t_stacks **stack_a)
{
    if(ac == 2)
        create_v2_stack_a(stack_a, av);
    else
        create_v1_stack_a(stack_a, ac ,av);
}