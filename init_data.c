#include "pipex.h"

void initialize_str_data(char_variables *str_data)
{
    str_data->cmd1 = NULL;
    str_data->cmd2 = NULL;
    str_data->final_path = NULL;
    str_data->path = NULL;
    str_data->tmp_cmd = NULL;
}
