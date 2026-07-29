#include "pipex.h"

void command_type_check_1(char_variables *str_data, char **envp)
{
    int i;
    
    str_data->cmd1 = ft_split(str_data->av[2], ' ');
    split_NULL_return_check(str_data, 1);

    if(char_search(str_data->cmd1[0], '/') == 1){
        execute_cmd_one(str_data, envp);
    }
    else{
        str_data->tmp_cmd = ft_strjoin("/", str_data->cmd1[0]);
        join_NULL_return_check(str_data);
        i = 0;
        while(str_data->path[i] != NULL){
            path_search_and_execute_one(str_data, envp, i);
            i++;
        }
        command_not_found_error(str_data);
    }
}

void command_type_check_2(char_variables *str_data, char **envp)
{
    int i;

    str_data->cmd2 = ft_split(str_data->av[3], ' ');
    split_NULL_return_check(str_data, 2);

    if(char_search(str_data->cmd2[0], '/') == 1){
        execute_cmd_two(str_data, envp);
    }
    else{
        str_data->tmp_cmd = ft_strjoin("/", str_data->cmd2[0]);
        join_NULL_return_check(str_data);
        i = 0;
        while(str_data->path[i] != NULL){
            path_search_and_execute_two(str_data, envp, i);
            i++;
        }
        command_not_found_error(str_data);
    }
}