#include "pipex.h"

void free_command_1(char_variables *str_data)
{
    int i;

    i = 0;
    while(str_data->cmd1[i])
        free(str_data->cmd1[i++]);
    free(str_data->cmd1);

}

void free_command_2(char_variables *str_data)
{
    int i;

    i = 0;
    while(str_data->cmd2[i])
        free(str_data->cmd2[i++]);
    free(str_data->cmd2);
}

void free_path(char_variables *str_data)
{
    int i;

    i = 0;
    while(str_data->path[i])
        free(str_data->path[i++]);
    free(str_data->path);
}

void free_final_path(char_variables *str_data)
{
    free(str_data->final_path);
    str_data->final_path = NULL;
}

void free_tmp_cmd(char_variables *str_data)
{
    free(str_data->tmp_cmd);
    str_data->tmp_cmd = NULL;
}
