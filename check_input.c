#include "push_swap.h"

void check_input_data(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while(i < ac)
    {
        if(av[i][0] == '\0')
            print_error();
        j = 0;
        while(av[i][j])
        {
            if(j == 0 && av[i][j] == '-' && is_num(av[i][j + 1]))
                j++;
            else if(is_num(av[i][j]))
                j++;
            else 
                print_error();
        }
        i++;
    }
}