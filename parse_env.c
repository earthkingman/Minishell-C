/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 02:01:56 by ji-park           #+#    #+#             */
/*   Updated: 2021/10/13 02:01:56 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env *env_last(t_env *lst)
{
    t_env   *tmp;

    if (lst == 0){
        return ((void *)0);
    }
    tmp = lst;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    return tmp;
}

void    env_add_back(t_env **lst, t_env *new)
{
    t_env   *last;

    if ((*lst) == NULL)
        *lst = new;
    else
    {
        last = env_last(*lst);
        last->next = new;
        new->prev = last;
    }
}

t_env   *parse_env(char **envp) 
{
    t_env   *env_list;
    t_env   *tmp;
    char    **splits;

    env_list = 0;
    while (*envp)
    {
        tmp = (t_env *)malloc(sizeof(t_env));
        splits = ft_split(*envp, '=');
        tmp->key = ft_strdup(splits[0]);
        tmp->value = ft_strdup(splits[1]);
        tmp->prev = 0;
        tmp->next = 0;
        env_add_back(&env_list, tmp);
        free_split(splits);
        envp++;
    }
    return (env_list);
}