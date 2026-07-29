#include "pipex.h"

void child_one_process(int_variables *num_data, char_variables *str_data, char **envp)
{
    close(num_data->p_fd[0]);
    num_data->infile_fd = get_infile_fd(str_data, num_data);
    dup2_function_call(num_data, str_data, 1);
    close(num_data->p_fd[1]);
    close(num_data->infile_fd);
    command_type_check_1(str_data, envp);
}

void child_two_process(int_variables *num_data, char_variables *str_data, char **envp)
{
    close(num_data->p_fd[1]);
    num_data->outfile_fd = get_outfile_fd(str_data);
    dup2_function_call(num_data, str_data, 2);
    close(num_data->outfile_fd);
    close(num_data->p_fd[0]);
    command_type_check_2(str_data, envp);
}