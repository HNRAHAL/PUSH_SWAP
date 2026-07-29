#include "pipex.h"

void execve_error_check(char_variables *str_data){
    perror("execve");
    free_allocated_data(str_data);
    exit(EXIT_FAILURE);
}


void command_not_found_error(char_variables *str_data)
{
    str_data->final_path = NULL;
    free_allocated_data(str_data);
    write(2, "error: Command not found\n", 26);
    exit(EXIT_FAILURE);
}

void join_NULL_return_check(char_variables *str_data){

    if(str_data->tmp_cmd == NULL){
        write(2, "error: Unable to join command\n", 31);
        free_allocated_data(str_data);
        exit(EXIT_FAILURE);
    }
}

void split_NULL_return_check(char_variables *str_data, int proc_num)
{
    if(proc_num == 1){
        if(str_data->cmd1 == NULL){
            write(2, "error: Unable to split command one\n", 36);
            free_allocated_data(str_data);
            exit(EXIT_FAILURE);
        }
    }
    else if(proc_num == 2){
        if(str_data->cmd2 == NULL){
            write(2, "error: Unable to split command two\n", 36);
            free_allocated_data(str_data);
            exit(EXIT_FAILURE);
        }
    }
}
