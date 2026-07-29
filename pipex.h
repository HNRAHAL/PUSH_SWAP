#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
// #include <sys/wait.h>

typedef struct t_int_vars
{
    int     p_fd[2];
    int     fork_id_1;
    int     fork_id_2;
    int     infile_fd;
    int     outfile_fd;
}           int_variables;

typedef struct char_vars
{
    char    *infile;
    char    *outfile;
    char    **av;
    char    **cmd1;
    char    **cmd2;
    char    **path;
    char    **single_path;
    char    *tmp_cmd;
    char    *final_path;
}           char_variables;



//  CHECKS
void    command_empty_check(char_variables *str_data, int ac);
void    envp_empty_check(char **envp);
void    arg_count_check(int ac);
void    path_empty_check(char **path);

//  INIT DATA
void    initialize_str_data(char_variables *str_data);

//  PATH
char    **return_PATH_directories(char **envp);
void    path_empty_check(char **path);

//  PIPE
void    pipe_function(int_variables *num_data, char_variables *str_data, char **envp);
void    pipe_error_handel(char_variables *str_data);


//  FORK
void    fork_error_handle(int_variables *num_data, char_variables *str_data, int proc_num);

//  CHILD
void    child_one_process(int_variables *num_data, char_variables *str_data, char **envp);
void    child_two_process(int_variables *num_data, char_variables *str_data, char **envp);

//  FILE DESCRIPTOR
int     get_infile_fd(char_variables *str_data, int_variables *num_data);
int     get_outfile_fd(char_variables *str_data);

//  DUP2
void    dup2_error_check(char_variables *str_data, int_variables *num_data, int proc_num);
void    dup2_function_call(int_variables *num_data, char_variables *str_data, int proc_num);

//  EXECUTE

// normal input commands
void    path_search_and_execute_one(char_variables *str_data, char **envp, int i);
void    path_search_and_execute_two(char_variables *str_data, char **envp, int i);
// path input commands
void    execute_cmd_one(char_variables *str_data, char **envp);
void    execute_cmd_two(char_variables *str_data, char **envp);

//  COMMAND INPUT CHECK
void    command_type_check_1(char_variables *str_data, char **envp);
void    command_type_check_2(char_variables *str_data, char **envp);

//  ERROR
void    split_NULL_return_check(char_variables *str_data, int proc_num);
void    join_NULL_return_check(char_variables *str_data);
void    command_not_found_error(char_variables *str_data);
void    execve_error_check(char_variables *str_data);

//  UTILS
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char *str, char c);
int     char_search(const char *s, char c);
int     ft_strlen(const char *str);

//  FREE
void    free_allocated_data(char_variables *str_data);
void    free_command_1(char_variables *str_data);
void    free_command_2(char_variables *str_data);
void    free_path(char_variables *str_data);
void    free_final_path(char_variables *str_data);
void    free_tmp_cmd(char_variables *str_data);



#endif