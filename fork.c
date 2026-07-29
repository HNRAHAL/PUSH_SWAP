#include "pipex.h"

void fork_error_handle(int_variables *num_data, char_variables *str_data, int proc_num)
{
    if(proc_num == 1)
    {
        if(num_data->fork_id_1 == -1){
            perror("fork");
            close(num_data->p_fd[0]);
            close(num_data->p_fd[1]);
            free_allocated_data(str_data);
            exit(EXIT_FAILURE);
        }
    }
    else if(proc_num == 2)
    {
        if(num_data->fork_id_2 == -1)
        {
            perror("fork");
            close(num_data->p_fd[0]);
            close(num_data->p_fd[1]);
            free_allocated_data(str_data);
            exit(EXIT_FAILURE);
        }
    }
}