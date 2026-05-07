#include "push_swap.h"

int is_num(char c)
{
    if(c >= '0' && c <= '9')
        return (1);
    return (0);
}

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

void overflow_check(long num)
{
    if((num > INT_MAX )||( num < INT_MIN))
        print_error();
}

void convert_num(int sign, char str, long *num)
{
    int digit = str - '0';

    if (sign == 1 && (*num > (LONG_MAX - digit) / 10))
        print_error();
    if (sign == -1 && (-(*num) < (LONG_MIN + digit) / 10))
        print_error();

    *num = *num * 10 + digit;
}

long ft_atol(const char *str)
{
    long num;
    int sign;
    int i;

    num = 0;
    sign = 1;
    i = 0;

    while(str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    while(is_num(str[i]))
    {
        convert_num(sign, str[i], &num);
        i++;
    }
    num *= sign;
    overflow_check(num);
    return(num);
}

void print_error(void)
{
    write(1, "Error\n", 6);
    exit(1);
}
