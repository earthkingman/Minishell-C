#include <minishell.h>

void    free_split(char **s)
{
    char    **tmp;

    tmp = s;
    while (*s)
    {
        free(*s);
        s++;
    }
    free(tmp);
}