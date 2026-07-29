#include "pipex.h"

void execute_cmd_one(char_variables *str_data, char **envp)
{
    if(access(str_data->cmd1[0], X_OK) == 0){
        if(execve(str_data->cmd1[0], str_data->cmd1, envp) == -1)
            execve_error_check(str_data);
    }
    else
        command_not_found_error(str_data);
}

void execute_cmd_two(char_variables *str_data, char **envp)
{
    if(access(str_data->cmd2[0], X_OK) == 0){
        if(execve(str_data->cmd2[0], str_data->cmd2, envp) == -1)
            execve_error_check(str_data);
    }
    else
        command_not_found_error(str_data);
}

void path_search_and_execute_one(char_variables *str_data, char **envp, int i)
{
    str_data->final_path = ft_strjoin(str_data->path[i], str_data->tmp_cmd);
    join_NULL_return_check(str_data);
    if(access(str_data->final_path, X_OK) == 0){
        if(execve(str_data->final_path, str_data->cmd1, envp) == -1)
            execve_error_check(str_data);
    }
    free(str_data->final_path);
}

void path_search_and_execute_two(char_variables *str_data, char **envp, int i)
{
    str_data->final_path = ft_strjoin(str_data->path[i], str_data->tmp_cmd);
    join_NULL_return_check(str_data);
    if(access(str_data->final_path, X_OK) == 0){
        if(execve(str_data->final_path, str_data->cmd2, envp) == -1)
            execve_error_check(str_data);
    }
    free(str_data->final_path);
}