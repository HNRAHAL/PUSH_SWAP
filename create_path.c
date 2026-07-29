#include "pipex.h"

void path_empty_check(char **path)
{
    if(path == NULL || path[0] == NULL){
        write(2, "error: No path was returned\n", 29);
        exit(EXIT_FAILURE);
    }
}

char **return_PATH_directories(char **envp)
{
    int i;
    char **path;

    i = 0;
    while(envp[i])
    {
        if(ft_strncmp(envp[i], "PATH=", 5) == 0)
            break;
        i++;
    }

    if(envp[i] == NULL)
        exit(EXIT_FAILURE);

    path = ft_split(envp[i] + 5, ':');
    path_empty_check(path);
    return path;
}