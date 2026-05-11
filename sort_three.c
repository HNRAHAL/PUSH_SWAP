#include "push_swap.h"

void sort_three_conditions(t_stacks **stack_a, int num1, int num2, int num3)
{
    if(num1 > num2 && num1 < num3 && num2 < num3)
        swap_op(stack_a, 'a');
    else if(num1 < num2 && num1 > num3 && num2 > num3)
        rev_rot_op(stack_a,'a', 0);
    else if(num1 < num2 && num1 < num3 && num2 > num3)
    {
        rev_rot_op(stack_a,'a', 0);
        swap_op(stack_a, 'a');
    }
    else if(num1 > num2 && num1 > num3 && num2 > num3)
    {
        rot_op(stack_a,'a', 0);
        swap_op(stack_a, 'a');
    }
    else if(num1 > num2 && num1 > num3 && num2 < num3)
        rot_op(stack_a,'a', 0);
    else
        return;
}

void sort_three(t_stacks **stack_a)
{
    t_stacks    *tmp;
    int         num1;
    int         num2;
    int         num3;

    tmp = *stack_a;
    num1 = tmp->num;
    num2 = tmp->next->num;
    num3 = tmp->next->next->num;
    sort_three_conditions(stack_a, num1, num2, num3);
}
