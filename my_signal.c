/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 01:54:46 by ji-park           #+#    #+#             */
/*   Updated: 2021/10/13 02:04:59 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    main_signal(int sig_number)
{
    if (sig_number == SIGINT)
    {
        rl_replace_line("",0);
        if (g_data->forked == 0 && g_data->count == 0)
            write(1,"\n$", 3);
        else if (g_data->forked == 1)
            write(1, "\n", 1);
        g_data->ret = 130;
        rl_redisplay();
    }
    else if (sig_number == SIGQUIT)
    {
        if (g_data->forked == 1)
        {
            write(1, "Quit\n", 5);
            g_data->ret = 131;
        }
        else if (g_data->forked == 0 && g_data->count == 0)
        {
            rl_on_new_line();
			rl_redisplay();
        }
    }
    else if (sig_number == SIGCHLD)
        g_data->count = g_data->count - 1;
}