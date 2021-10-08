/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:23:32 by ji-park           #+#    #+#             */
/*   Updated: 2021/10/08 22:26:07 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <termios.h>
# include <termcap.h>
# include <signal.h>
# include "libft.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}				t_env;

typedef struct s_sh_data
{
	t_env			*env_list;
	char			*input;
	char			**envp;
	int				stdin;
	int				stdout;
	int				origin_stdin;
	int				origin_stdout;
	struct termios	main_term;
	struct termios	child_term;
	int				signal;
	int				ret;
	int				forked;
	int				herodoc_fd;
	char			*cl;
	char			*cm;
	char			*ce;
	int				last_pid;
	int				status;
	int				count;
}					t_sh_data;

t_sh_data	*g_data;

#endif