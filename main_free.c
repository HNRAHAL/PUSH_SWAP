#include "pipex.h"

void free_allocated_data(char_variables *str_data)
{
    if(str_data->cmd1 != NULL)
        free_command_1(str_data);
    if(str_data->cmd2 != NULL)
        free_command_2(str_data);
    if(str_data->path != NULL)
        free_path(str_data);
    if(str_data->final_path != NULL)
        free_final_path(str_data);
    if(str_data->tmp_cmd != NULL)
        free_tmp_cmd(str_data);
}