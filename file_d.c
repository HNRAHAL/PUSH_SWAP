#include "pipex.h"

int get_infile_fd(char_variables *str_data, int_variables *num_data)
{
    int infile_fd = open(str_data->av[1] , O_RDONLY);
    if(infile_fd == -1){
        perror("open");
        close(num_data->p_fd[1]);
        free_allocated_data(str_data);
        exit(EXIT_FAILURE);
    }
    return(infile_fd);
}

int get_outfile_fd(char_variables *str_data)
{
    int outfile_fd;

    outfile_fd = open(str_data->av[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if(outfile_fd == -1){
        perror("open");
        free_allocated_data(str_data);
        exit(EXIT_FAILURE);
    }
    return(outfile_fd);
}