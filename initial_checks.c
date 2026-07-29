#include "pipex.h"

void envp_empty_check(char **envp)
{
    if(envp == NULL || envp[0] == NULL){
        write(STDERR_FILENO,"error: empty envp\n", 19);
        exit(EXIT_FAILURE);
    }
}

void arg_count_check(int ac)
{
    if((ac < 5) || (ac > 5)){
        write(2, "error: Expected 5 arguments:\n\t./pipex infile <cmd1> <cmd2> outfile\n", 67);
        exit(EXIT_FAILURE);
    }
}

void command_empty_check(char_variables *str_data, int ac)
{
    int i;

    i = 1;
    while(i < ac){
        if((str_data->av[i] == NULL) || (str_data->av[i][0] == '\0')){
            write(2, "error: Empty argument\n", 23);
            exit(EXIT_FAILURE);
        }
        i++;
    }
}