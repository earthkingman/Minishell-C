#include "minishell.h"

void    init_setting(char **envp)
{
    g_data = (t_sh_data *)malloc(sizeof(t_sh_data));
    g_data->env_list = parse_env(envp);
    g_data->stdin = 0;
    g_data->stdout = 1;
}