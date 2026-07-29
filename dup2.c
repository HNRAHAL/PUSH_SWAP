#include "pipex.h"

void dup2_error_check(char_variables *str_data, int_variables *num_data, int proc_num){
    if(proc_num == 1){
        close(num_data->infile_fd);
        close(num_data->p_fd[1]);
    }
    else if(proc_num == 2){
        close(num_data->outfile_fd);
        close(num_data->p_fd[0]);
    }
    perror("dup2");
    free_allocated_data(str_data);
    exit(EXIT_FAILURE);
}

void dup2_function_call(int_variables *num_data, char_variables *str_data, int proc_num)
{
    if(proc_num == 1){
        if(dup2(num_data->infile_fd, STDIN_FILENO) == -1)
            dup2_error_check(str_data, num_data, 1);
        if(dup2(num_data->p_fd[1], STDOUT_FILENO) == -1)
            dup2_error_check(str_data, num_data, 1);
    }
    else if(proc_num == 2){
        if(dup2(num_data->outfile_fd, STDOUT_FILENO) == -1)
            dup2_error_check(str_data, num_data, 2);
        if(dup2(num_data->p_fd[0], STDIN_FILENO) == -1)
            dup2_error_check(str_data, num_data, 2);
    }
}
