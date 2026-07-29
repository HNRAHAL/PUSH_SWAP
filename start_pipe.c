#include "pipex.h"

void pipe_error_handel(char_variables *str_data)
{
    perror("pipe");
    free_allocated_data(str_data);
    exit(EXIT_FAILURE);
}

void pipe_function(int_variables *num_data, char_variables *str_data, char **envp)
{
    if(pipe(num_data->p_fd) == -1)
        pipe_error_handel(str_data);
    num_data->fork_id_1 = fork();
    fork_error_handle(num_data, str_data, 1);
    if(num_data->fork_id_1 > 0)
    {
        num_data->fork_id_2 = fork();
        fork_error_handle(num_data, str_data, 2);
        if(num_data->fork_id_2 == 0)
            child_two_process(num_data, str_data, envp);
        else{
            close(num_data->p_fd[0]);
            close(num_data->p_fd[1]);
        }   
    }
    else 
        child_one_process(num_data, str_data, envp);
}