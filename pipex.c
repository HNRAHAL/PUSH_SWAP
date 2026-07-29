#include "pipex.h"

int main(int ac, char **av, char **envp)
{
    int_variables num_data;
    char_variables str_data;

    str_data.av = av;
    arg_count_check(ac);
    command_empty_check(&str_data, ac);
    envp_empty_check(envp);
    initialize_str_data(&str_data);
    str_data.path = return_PATH_directories(envp);
    pipe_function(&num_data, &str_data, envp);
    // waitpid(num_data.fork_id_1, NULL, 0);
    // waitpid(num_data.fork_id_2, NULL, 0);
    free_allocated_data(&str_data);
    return (0);
}
