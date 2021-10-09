#include "minishell.h"

void    init_setting(char **envp)
{
    g_data = (t_sh_data *)malloc(sizeof(t_sh_data));
    g_data->env_list = parse_env(envp);
    g_data->stdin = 0;
    g_data->stdout = 1;
    /**
     *  밑에 변수는 뭔지 모르겠어요
     */
    g_data->origin_stdin = dup(0);
	g_data->origin_stdout = dup(1);
	g_data->envp = envp;
	g_data->forked = 0;
	g_data->signal = 0;
	// signal(SIGINT, main_signal);
	// signal(SIGQUIT, main_signal);
	// signal(SIGCHLD, main_signal);
	// init_term2();
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    init_setting(envp);
    return (0);
}